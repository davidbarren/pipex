/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:59:25 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/25 16:10:29 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_generic(t_pipex *pipex, char **envp)
{
	if (!pipex->pid_index)
		child_in_bonus(pipex->av, pipex, envp);
	if (pipex->pid_index == (pipex->ac - 1))
		child_out_bonus(pipex->av, pipex, envp);
	dup2(pipex->io_fds[pipex->pid_index - 1][0], STDIN_FILENO);
	dup2(pipex->io_fds[pipex->pid_index][1], STDOUT_FILENO);
	close_pipes(pipex);
	exec_command(pipex, pipex->av, envp, pipex->av_index);
}

void	spawn_children(char **envp, t_pipex *pipex)
{
	int	i;

	pipex->child_pid = malloc((pipex->ac - 2) * (sizeof(pid_t)));
	if (!pipex->child_pid)
	{
		perror("pipex:");
		ft_error_exit(MALLOC_FAIL, pipex);
	}
	pipex->av_index = 2;
	while (pipex->pid_index <= (pipex->pipecount + 1))
	{
		pipex->child_pid[pipex->pid_index] = fork();
		if (pipex->child_pid[pipex->pid_index] == -1)
		{
			ft_printerror("Error goes here");
		}
		pipex->av_index++;
		if (pipex->child_pid[pipex->pid_index++] == 0)
			child_generic(pipex, envp);
	}
	while (i < pipex->pid_index)
		waitpid(pipex->child_pid[i++], NULL, 0);
	if (pipex->paths)
		free_split(pipex->paths);
	return ;
}
