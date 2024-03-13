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
	int		pid;
	int		fd;
	char	**paths;
	int		pid_index;
	int		av_index;
	char	*exec_path;
	char	**parsed_cmd;
	int		*status_in;
	int		*status_out;
}	t_pipex;

/* ************************************************************************** */
/*  Error Handling Functions                                                  */
/* ************************************************************************** */
int		check_args(int ac, t_pipex *pipex);
void	ft_error_exit(void);
void	get_path(char **envp, t_pipex *pipex);
/* ************************************************************************** */
/*  Parent_Process.c                                                          */
/* ************************************************************************** */
void	init_forks(char **av, char **envp, t_pipex *pipex);
void	exec_command(t_pipex *pipex, char **argv, char **envp, int an);
char	*ft_strjoin_sep(char *s1, char *s2, char sep);
void	prep_command(char *cmd, t_pipex *pipex);
/* ************************************************************************** */
/*  Parent_Process.c                                                          */
/* ************************************************************************** */
void	child_input(char **av, t_pipex *pipex, char **envp);
void	child_output(char **av, t_pipex *pipex, char **envp);
#endif