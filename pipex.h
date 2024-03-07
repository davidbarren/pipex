/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:51:17 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/07 12:52:51 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H
# include "libft/includes/libft.h"
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		io_fds[2];
	char	buffer[30];
}	t_pipex;

/* ************************************************************************** */
/*  Error Handling Functions                                                  */
/* ************************************************************************** */
int		check_args(int ac, char **av, t_pipex *pipex);
void	ft_error_exit(void);

#endif