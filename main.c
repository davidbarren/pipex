/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:15:39 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/07 14:15:40 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	piper;

	if (!envp)
		ft_printf("Baboons!");
	if (!check_args(argc, &piper))
		ft_printf("wrong arg count! fix later!");
		// return (1);
	get_path(envp, &piper);
	// int	i = 0;
	// while (piper.paths[i])
		// ft_printf("%s\n", piper.paths[i++]);
	init_forks(argc, argv, envp, &piper);
	return (0);
}
