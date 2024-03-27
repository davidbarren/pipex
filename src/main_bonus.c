/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:15:39 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/27 17:58:41 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	piper;
	t_split	st;

	if (!*envp)
		return (ft_printerror("pipex: Environment not found"));
	ft_memset(&piper, 0, sizeof(t_pipex));
	ft_memset(&st, 0, sizeof(t_split));
	piper.sp = &st;
	piper.av = argv;
	piper.ac = argc;
	open_pipes(&piper);
	get_path(envp, &piper);
	spawn_children(envp, &piper);
	free(piper.child_pid);
	return (0);
}

void	free_pipes(int **data)
{
	int	i;

	i = 0;
	if (!data)
		return ;
	while (data[i])
		free(data[i++]);
	free(data);
	return ;
}

void	open_pipes(t_pipex *pipex)
{
	int	i;
	int	fd;

	i = 0;
	pipex->pipecount = (pipex->ac - 4);
	pipex->io_fds = ft_calloc(pipex->pipecount + 1, sizeof(int *));
	if (!pipex->io_fds)
	{
		perror("pipex:");
		ft_error_exit(0, pipex);
	}
	while (i <= pipex->pipecount)
	{
		pipex->io_fds[i] = malloc (2 * sizeof (int));
		fd = pipe(pipex->io_fds[i]);
		if (fd == -1)
		{
			perror("pipex:");
			free_pipes(pipex->io_fds);
			exit (127);
		}
		i++;
	}
	pipex->pipe_fl = 1;
}

void	close_pipes(t_pipex *pipex)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	if (pipex->pipe_fl == 1)
	{
		while (i < pipex->pipecount)
		{
			status = close(pipex->io_fds[i][0]);
			if (status == -1)
			{
				perror("pipex:");
				ft_error_exit(0, pipex);
			}
			status = close(pipex->io_fds[i][1]);
			if (status == -1)
			{
				perror("pipex:");
				ft_error_exit(0, pipex);
			}
			free(pipex->io_fds[i++]);
		}
	}
}
