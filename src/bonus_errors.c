/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:38:06 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/28 16:58:52 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error_exit_b(int errnum, t_pipex *pipex, int arg)
{
	if (errnum == EMPTY_STR || errnum == BAD_PERM)
		ft_printerror("pipex: permission denied: %s\n",
			pipex->av[arg]);
	if (errnum == FAKE_CMD)
		ft_printerror("pipex: command not found: %s\n", \
		pipex->av[arg]);
	if (errnum == NO_INPUT)
	{
		ft_printerror("pipex: No such file or directory: %s\n", pipex->av[arg]);
	}
	if (errnum == NO_PATH)
		return ;
	if (errnum == FAKE_FILE)
	{
		ft_printerror("pipex: No such file or directory: %s\n", pipex->av[arg]);
		exit (FAKE_FILE);
	}
	if (pipex->paths_fl)
		free_split(pipex->paths);
	if (pipex->parsed_fl)
		free_split(pipex->parsed_cmd);
	exit (errnum);
}
