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

void	free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	piper;

	piper.fok_flag = 0;
	piper.xok_flag = 0;
	piper.av = argv;
	if (!envp)
		ft_error_exit(NO_PATH, &piper);
	if (!check_args(argc, &piper))
		perror("Pipex:");
	get_path(envp, &piper);
	init_forks(argv, envp, &piper);
	// system("leaks pipex");
	return (0);
}
