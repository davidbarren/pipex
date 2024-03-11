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

void	init_forks(int ac, char **av, char **envp, t_pipex *pipex)
{
	pipex->pid_index = 0;
	pipex->pid = malloc((ac - 3) * sizeof(int));
	ft_memset(pipex->pid, 42, sizeof(pipex->pid));
	if (!pipex->pid)
		exit (-1);
	pipex->pid[0] = fork();
	if (pipex->pid[0] == 0)
		exec_command(pipex, av, envp);
	return ;
}
