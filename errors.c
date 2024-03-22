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
	if (errnum == EMPTY_STR || errnum == BAD_PERM)
		ft_printerror("pipex: permission denied: %s\n",
			pipex->av[pipex->av_index]);
	if (errnum == FAKE_CMD)
		ft_printerror("pipex: command not found: %s\n", \
		pipex->av[pipex->av_index]);
	if (errnum == NO_INPUT)
	{
		ft_printerror("pipex: No such file or directory: %s\n",
			pipex->av[pipex->av_index]);
	}
	if (errnum == NO_PATH)
		return ;
	if (errnum == FAKE_FILE)
	{
		ft_printerror("pipex: No such file or directory: %s\n", pipex->av[1]);
		exit (FAKE_FILE);
	}
	free_split(pipex->paths);
	free_split(pipex->parsed_cmd);
	exit (errnum);
}
