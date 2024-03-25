/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:15:39 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/25 17:23:08 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	piper;
	t_split	st;

	if (!*envp)
		return (ft_printerror("pipex: Environment not found"));
	ft_memset(&piper, 0, sizeof(t_pipex));
	ft_memset(&st, 0, sizeof(t_split));
	piper.sp = &st;
	piper.av = argv;
	if (!check_args(argc, &piper))
		perror("pipex:");
	get_path(envp, &piper);
	init_forks(argv, envp, &piper);
	return (0);
}
