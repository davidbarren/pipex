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
	prep_command(argv[2], pipex);
	while (pipex->paths[i])
	{
		status = access(pipex->paths[i], X_OK);
			if (!status)
			{
				status = execve(pipex->paths[i], pipex->parsed_cmd, envp);
		 		if (status == -1)
					ft_printf("execve failed\n");
			}
				i++;
	}
}

void	prep_command(char *cmd, t_pipex *pipex)
{
	int	i;

	i = 0;
	if (!ft_strncmp(cmd, "./", 2))
		cmd += 2;
	if (ft_strchr(cmd, ' '))
		pipex->parsed_cmd = ft_split(cmd, ' ');
	else
		pipex->parsed_cmd = &cmd;
	if (!pipex->parsed_cmd)
		ft_printf("HUH?");
	while (pipex->paths[i])
	{
		pipex->paths[i]= ft_strjoin_sep(pipex->paths[i], pipex->parsed_cmd[0], '/');
		i++;
	}
	// i = 0;
	// while (pipex->paths[i])
	// 	ft_printf("Path:%s\n", pipex->paths[i++]);
	// i = 0;
	// while (pipex->parsed_cmd[i])
	// 	ft_printf("Parsed_cmd:%s\n", pipex->parsed_cmd[i++]);
}
