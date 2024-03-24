/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:15:39 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/24 16:54:52 by dbarrene         ###   ########.fr       */
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

	ft_memset(&piper, 0, sizeof(t_pipex));
	ft_memset(&st, 0, sizeof(t_split));
	piper.sp = &st;
	piper.fok_flag = 0;
	piper.xok_flag = 0;
	piper.av = argv;
	open_pipes(argc, &piper);
	get_path(envp, &piper);
	init_forks(argv, envp, &piper);
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

void	open_pipes(int ac, t_pipex* pipex)
{
	int	i;

	i = 0;
	pipex->pipecount = (ac - 3);
	pipex->io_fds = malloc(pipex->pipecount * sizeof(int *));
	if (!pipex->io_fds)
	{
		perror("pipex:");
		ft_error_exit(0, pipex);	
	}
	while (i <= pipex->pipecount)
	{
		pipex->io_fds[i] = malloc (2 * sizeof (int));
		pipex->fd = pipe(pipex->io_fds[i]);
		if (pipex->fd == -1)
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
	while (i <= pipex->pipecount)
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
		i++;
	}
	if (pipex->pipe_fl == 1)
		free_pipes(pipex->io_fds);
}
