/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:26:15 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/27 18:33:09 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin_sep(char *s1, char *s2, char sep)
{
	char	*joined;
	int		i;

	if (!s1 || !s2 || sep == '\0')
		return (NULL);
	i = 0;
	joined = malloc (ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!joined)
		return (NULL);
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	joined[i++] = sep;
	while (*s2)
		joined[i++] = *s2++;
	joined[i] = 0;
	free (s1);
	return (joined);
}

void	pre_split_checks(char *cmd, t_pipex *pipex)
{
	if (!ft_strncmp(cmd, ".", 3))
	{
		ft_printerror("%s: not enough arguments\n", cmd);
		exit (50);
	}
	if (!pipex->paths)
		ft_error_exit(FAKE_CMD, pipex);
	if (!ft_strlen(cmd))
		ft_error_exit(BAD_PERM, pipex);
	if (!ft_strncmp(cmd, "./", 4))
		ft_error_exit(EMPTY_STR, pipex);
}
