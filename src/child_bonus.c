/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:05:34 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/27 17:59:26 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_in_bonus(char **av, t_pipex *pipex, char **envp)
{
	int	fd_in;
	int	status;

	fd_in = open(av[1], O_RDONLY);
	if (fd_in == -1)
		ft_error_exit(FAKE_FILE, pipex);
	status = dup2(fd_in, STDIN_FILENO);
	if (status == -1)
	{
		perror("pipex:");
		ft_error_exit(0, pipex);
	}
	status = dup2(pipex->io_fds[0][1], STDOUT_FILENO);
	if (status == -1)
	{
		perror("pipex dup failed:");
		ft_error_exit(0, pipex);
	}
	close_pipes(pipex);
	exec_command(pipex, av, envp, 2);
}

void	child_out_bonus(char **av, t_pipex *pipex, char **envp)
{
	int	fd_out;

	fd_out = open(av[pipex->ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
		ft_error_exit(FAKE_FILE, pipex);
	dup2(fd_out, STDOUT_FILENO);
	dup2(pipex->io_fds[pipex->pid_index - 1][0], STDIN_FILENO);
	close_pipes(pipex);
	exec_command(pipex, av, envp, pipex->av_index);
}

void	child_generic(t_pipex *pipex, char **envp)
{
	if (!pipex->pid_index && !pipex->hdoc_flag)
		child_in_bonus(pipex->av, pipex, envp);
	if (pipex->pid_index == (pipex->ac - 4))
		child_out_bonus(pipex->av, pipex, envp);
	if (dup2(pipex->io_fds[pipex->pid_index - 1][0], STDIN_FILENO) == -1)
	{
		perror("pipex dup failed:");
		ft_error_exit(0, pipex);
	}
	if (dup2(pipex->io_fds[pipex->pid_index][1], STDOUT_FILENO) == -1)
	{
		perror("pipex dup failed:");
		ft_error_exit(0, pipex);
	}
	close_pipes(pipex);
	exec_command(pipex, pipex->av, envp, pipex->av_index);
}
