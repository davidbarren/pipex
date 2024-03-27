/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:59:25 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/27 17:51:26 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	spawn_children(char **envp, t_pipex *pipex)
{
	pipex->child_pid = malloc((pipex->ac - 2) * (sizeof(pid_t)));
	if (!pipex->child_pid)
	{
		perror("pipex:");
		ft_error_exit(MALLOC_FAIL, pipex);
	}
	pipex->av_index = 2;
	while (pipex->pid_index < (pipex->pipecount + 1))
	{
		pipex->child_pid[pipex->pid_index] = fork();
		if (pipex->child_pid[pipex->pid_index] == -1)
		{
			ft_printerror("Error goes here");
			break ;
		}
		if (pipex->child_pid[pipex->pid_index] == 0)
			child_generic(pipex, envp);
		pipex->av_index++;
		pipex->pid_index += 1;
	}
	close_pipes(pipex);
	while (pipex->iter < pipex->pid_index)
		waitpid(pipex->child_pid[pipex->iter++], NULL, 0);
	if (pipex->paths)
		free_split(pipex->paths);
}
