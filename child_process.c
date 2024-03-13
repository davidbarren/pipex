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
				if (exec_st == -1)
					ft_printf("execve failed\n");
			}
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
	pipex->parsed_cmd = ft_split(cmd, ' ');
	if (!pipex->parsed_cmd)
		ft_printf("HUH?");
	while (pipex->paths[i])
	{
		pipex->paths[i] = ft_strjoin_sep(pipex->paths[i], \
		pipex->parsed_cmd[0], '/');
		i++;
	}
}
