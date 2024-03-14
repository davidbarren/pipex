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
	pid_t	pid[2];

	pid[0] = fork();
	if (pid[0] == 0)
		child_input(av, pipex, envp);
	waitpid(pid[0], NULL, 0);
	close(pipex->io_fds[1]);
	pid[1] = fork();
	if (pid[1] == 0)
		child_output(av, pipex, envp);
	waitpid(pid[1], NULL, 0);
	// free_split(pipex->parsed_cmd);
	return ;
}
