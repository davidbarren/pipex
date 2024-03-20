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
	if (errnum == -5)
		ft_printerror("File does not exist \n");
	free_split(pipex->paths);
	free_split(pipex->parsed_cmd);
	exit (errnum);
}
