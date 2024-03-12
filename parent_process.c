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
	if (ac)
		ft_printf("ac exists :)\n");
	// if (!pipex->pid)
	// 	exit (-1);
	// pipex- >pid[0] = fork();
	// if (pipex->pid[0] == 0)
	exec_command(pipex, av, envp);
	return ;
}
