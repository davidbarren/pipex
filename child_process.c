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

void	exec_command(t_pipex *pipex, char **argv, char **envp)
{
	int	status;
	int	i;

	i = 0;
	while (pipex->paths[i])
	{
		status = access(pipex->paths[i], R_OK);
		if (status)
			ft_error_exit();
		status = execve(pipex->paths[i], argv, envp);
		if (status == -1)
			ft_error_exit();
		i++;
	}
}
