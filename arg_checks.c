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
		ft_printf("More than 4 args!");
		// return (0);
	pipex->fd = pipe(pipex->io_fds);
	if (pipex->fd == -1)
		return (0);
	return (1);
}

void	get_path(char **envp, t_pipex *pipex)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		path = ft_strnstr(envp[i], "PATH", ft_strlen(envp[i]));
		if (path)
			break ;
		i++;
	}
	if (!path)
		perror("Pipex");
	pipex->paths = ft_split(path, ':');
	i = 0;
	while (pipex->paths[i])
		ft_printf("%s\n", pipex->paths[i++]);
}
