/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:05:29 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/27 18:06:05 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_forks(char **av, char **envp, t_pipex *pipex)
{
	pid_t	pid[2];

	pid[0] = fork();
	if (pid[0] == -1)
	{
		perror("pipex:");
		ft_error_exit(69, pipex);
	}
	if (pid[0] == 0)
		child_input(av, pipex, envp);
	pid[1] = fork();
	if (pid[1] == -1)
		perror("pipex:");
	if (pid[1] == 0)
		child_output(av, pipex, envp);
	close(pipex->io_fds[0]);
	close(pipex->io_fds[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	if (pipex->paths)
		free_split(pipex->paths);
	return ;
}

void	free_path_remainders(t_pipex *pipex)
{
	int	i;
	int	remainder;


	i = 0;
	remainder = pipex->path_index + 1;
	while (i < pipex->path_index)
		free(pipex->paths[i++]);
	while (pipex->paths[remainder])
		free(pipex->paths[remainder++]);
}	
