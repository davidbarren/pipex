/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:19:04 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/07 14:19:05 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_args(int ac, char **av, t_pipex *pipex)
{
	if (ac != 5)
		return (0);
	pipex->io_fds[0] = open(av[1], O_RDONLY);
	pipex->io_fds[1] = open(av[4], O_WRONLY);
	if (pipex->io_fds[0] == -1 || pipex->io_fds[1] == -1)
		return (0);
	return (1);
}
