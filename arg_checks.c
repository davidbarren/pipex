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

int	check_args(int ac, t_pipex *pipex)
{
	if (ac != 5)
		return (0);
	pipex->fd = pipe(pipex->io_fds);
	if (pipex->fd == -1)
	{
		ft_error_exit(0);
		return (0);
	}
	return (1);
}

void	get_path(char **envp, t_pipex *pipex)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		path = ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]));
		if (path)
		{
			path += 5;
			break ;
		}
		i++;
	}
	if (!path)
		ft_error_exit(0);
	pipex->paths = ft_split(path, ':');
}
