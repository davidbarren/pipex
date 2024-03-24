/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:59:25 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/24 18:20:59 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_generic(t_pipex *pipex, char **envp)
{
	
}

void	spawn_children(char **envp, t_pipex *pipex)
{
	pipex->child_pid = malloc((pipex->ac - 2) * (sizeof(pid_t)));
	if (!pipex->child_pid)
	{
		perror("pipex:");
		ft_error_exit(MALLOC_FAIL, pipex);
	}
	pipex->child_pid[pipex->pid_index] = fork()
	if (pipex->child_pid[pipex->pid_index++] == 0)
	{

	}
	/* There is always 1 more child than pipecount, maybe put it in a while 
	 * to keep forking until we get to pipecount + 1, also keep in mind we might
	 * have to increment our av_index to keep track of the cmd we're on,
	 * might just send all of the child processes to child_generic and 
	 * include a check to see if pid_index == 0 or pid_index == pipecount + 1
	 * and then just call child_input or child_output accordingly. Also have
	 * to retool child output so that it reads from the last pipe as opposed to
	 * the first one like it does in non-bonus. */

}
