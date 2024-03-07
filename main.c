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
	int		pid;

	if (!envp)
		ft_printf("Baboons!");
	if (!check_args(argc, argv, &piper))
		ft_error_exit();
	pipe(piper.io_fds);
	ft_memset(&piper, 1, sizeof(piper));
	pid = fork();
	if (!pid)
	{
		// close(piper.io_fds[1]);
		write(1, &piper.buffer, 30);
		ft_printf("Greetings from the child!\n");
		// close(piper.io_fds[0]);
		return (1);
	}
	else if (pid)
	{
		// close(piper.io_fds[0]);
		read(piper.io_fds[0], piper.buffer, 30);
		ft_printf("Writing from main process :)\n");
		// close(piper.io_fds[1]);
		return (1);
	}
	ft_printf("buffer:%s\n", piper.buffer);
	return (1);
}
