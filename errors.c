/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:27:20 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/07 14:27:21 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_exit(int errnum, t_pipex *pipex)
{
	if (errnum == EMPTY_STR)
		ft_printerror("Pipex: permission denied:\n");
	if (errnum == FAKE_CMD)
		ft_printerror("Pipex: command not found: %s\n", \
		pipex->av[pipex->av_index]);
	if (errnum == NO_INPUT)
	{
		ft_printerror("Pipex: no such file or directory: %s\n", pipex->av[1]);
		exit (3);
	}
	if (errnum == NO_PATH)
	{
		return ;
	}
	free_split(pipex->paths);
	free_split(pipex->parsed_cmd);
	exit (errnum);
}
