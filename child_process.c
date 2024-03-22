/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:05:34 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/22 15:10:50 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_command(t_pipex *pipex, char **argv, char **envp, int an)
{
	int	exec_st;

	pipex->av_index = an;
	pipex->av = argv;
	prep_command(argv[an], pipex);
	check_access(pipex);
	if (!pipex->fok_flag)
		ft_error_exit(FAKE_CMD, pipex);
	if (!pipex->xok_flag)
	{
		perror("Pipex");
		exit (60);
	}
	exec_st = execve(pipex->paths[pipex->path_index], pipex->parsed_cmd, envp);
	if (exec_st == -1)
		ft_error_exit(FAKE_CMD, pipex);
}

void	prep_command(char *cmd, t_pipex *pipex)
{
	int	i;

	i = 0;
	if (!pipex->paths)
		ft_error_exit(FAKE_CMD, pipex);
	if (cmd[0] == '\0')
		ft_error_exit(EMPTY_STR, pipex);
	pipex->parsed_cmd = ft_split(cmd, ' ');
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK))
			ft_error_exit(NO_INPUT, pipex);
		pipex->paths[pipex->path_index] = pipex->parsed_cmd[0];
		return ;
	}
	if (!pipex->parsed_cmd)
		ft_error_exit(0, pipex);
	while (pipex->paths[i])
	{
		pipex->paths[i] = ft_strjoin_sep(pipex->paths[i], \
			pipex->parsed_cmd[0], '/');
		i++;
	}
	check_access(pipex);
}

void	child_input(char **av, t_pipex *pipex, char **envp)
{
	int	fd_in;

	fd_in = open(av[1], O_RDONLY);
	if (fd_in == -1)
	{
		perror("Pipex");
		exit(69);
	}
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	dup2(pipex->io_fds[1], STDOUT_FILENO);
	close(pipex->io_fds[1]);
	close(pipex->io_fds[0]);
	exec_command(pipex, av, envp, 2);
}

void	child_output(char **av, t_pipex *pipex, char **envp)
{
	int	fd_out;

	fd_out = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		perror("Pipex");
		exit (68);
	}
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	dup2(pipex->io_fds[0], STDIN_FILENO);
	close(pipex->io_fds[0]);
	exec_command(pipex, av, envp, 3);
}

void	check_access(t_pipex *pipex)
{
	int	i;
	int	fstatus;
	int	xstatus;

	i = 0;
	while (pipex->paths[i])
	{
		fstatus = access(pipex->paths[i], F_OK);
		if (!fstatus)
		{
			pipex->fok_flag = 1;
			xstatus = access(pipex->paths[i], X_OK);
			if (!xstatus)
			{
				pipex->xok_flag = 1;
				pipex->path_index = i;
				break ;
			}
		}
		i++;
	}
}
