/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:05:34 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/11 11:05:36 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_command(t_pipex *pipex, char **argv, char **envp, int an)
{
	int	acc_st;
	int	exec_st;
	int	i;

	i = 0;
	prep_command(argv[an], pipex);
	while (pipex->paths[i])
	{
		acc_st = access(pipex->paths[i], F_OK);
		if (!acc_st)
		{
			acc_st = access(pipex->paths[i], X_OK);
			if (!acc_st)
			{
				exec_st = execve(pipex->paths[i], pipex->parsed_cmd, envp);
				// if (exec_st == -1)
					// ft_error_exit();
			}
			// else if (acc_st == -1)
			// 	ft_error_exit();
		}
		// else if (acc_st == -1)
		// 	ft_error_exit();
		i++;
	}
}

void	prep_command(char *cmd, t_pipex *pipex)
{
	int	i;

	i = 0;
	if (cmd[0] == '\0')
		ft_error_exit(EMPTY_STR);
	if (!ft_strncmp(cmd, "./", 2))
		cmd += 2;
	pipex->parsed_cmd = ft_split(cmd, ' ');
	if (!pipex->parsed_cmd)
		ft_error_exit(0);
	while (pipex->paths[i])
	{
		pipex->paths[i] = ft_strjoin_sep(pipex->paths[i], \
		pipex->parsed_cmd[0], '/');
		i++;
	}
}

void	child_input(char **av, t_pipex *pipex, char **envp)
{
	int	fd_in;

	fd_in = open(av[1], O_RDONLY);
	if (fd_in == -1)
		ft_error_exit(0);
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

	fd_out = open(av[4], O_RDWR | O_CREAT, 0644);
	if (fd_out == -1)
		ft_error_exit(0);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	dup2(pipex->io_fds[0], STDIN_FILENO);
	close(pipex->io_fds[0]);
	exec_command(pipex, av, envp, 3);
}
