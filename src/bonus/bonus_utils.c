/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:59:25 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/24 17:35:46 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_generic(int an, t_pipex *pipex, char **envp)
{
}

void	spawn_children(char **envp, t_pipex *pipex)
{
	pipex->child_pid = malloc((pipex->ac - 2) * (sizeof(pid_t)));
	if (!pipex->child_pid)
	{
		perror("pipex:");
		ft_error_exit(MALLOC_FAIL, pipex);
	}

}
