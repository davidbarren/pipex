/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:05:29 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/11 11:05:30 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_forks(char **av, char **envp, t_pipex *pipex)
{
	int	local_pid;

	local_pid = fork();
	if (!local_pid)
		child_input(av, pipex, envp);
	else
	{
		pipex->pid = fork();
		if (!pipex->pid)
			child_output(av, pipex, envp);
		else
		{
			waitpid(local_pid, pipex->status_in, 0);
			waitpid(pipex->pid, pipex->status_out, 0);
		}
	}
	return ;
}

void	child_input(char **av, t_pipex *pipex, char **envp)
{
	int	fd_in;

	fd_in = open(av[1], O_RDONLY);
	if (fd_in == -1)
		ft_printerror("Add error message here :)\n");
	dup2(fd_in, STDIN_FILENO);
	dup2(pipex->io_fds[1], STDOUT_FILENO);
	close(fd_in);
	close(pipex->io_fds[1]);
	exec_command(pipex, av, envp, 2);
}

void	child_output(char **av, t_pipex *pipex, char **envp)
{
	int	fd_out;

	fd_out = open(av[4], O_WRONLY | O_CREAT);
	if (fd_out == -1)
		ft_printerror("Error opening or creating outfile\n");
	dup2(fd_out, STDOUT_FILENO);
	dup2(pipex->io_fds[0], STDIN_FILENO);
	close(fd_out);
	close(pipex->io_fds[0]);
	exec_command(pipex, av, envp, 3);
}
