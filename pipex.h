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
	int		fd;
	char	**paths;
	char	**parsed_cmd;
	int		fok_flag;
	int		xok_flag;
	int		path_index;
	char	**av;
	int		av_index;
}	t_pipex;

typedef enum s_errco
{
	EMPTY_STR = -1,
	FAKE_CMD = -2,
	NO_PATH = -3,
	BAD_PERM = -4,
	NO_INPUT = -5,
	FAKE_FILE = -6,
}	t_errco;

/* ************************************************************************** */
/*  Error Handling Functions                                                  */
/* ************************************************************************** */
int		check_args(int ac, t_pipex *pipex);
void	ft_error_exit(int errnum, t_pipex *pipex);
void	get_path(char **envp, t_pipex *pipex);
void	free_split(char **args);
/* ************************************************************************** */
/*  Parent_Process.c                                                          */
/* ************************************************************************** */
void	init_forks(char **av, char **envp, t_pipex *pipex);
char	*ft_strjoin_sep(char *s1, char *s2, char sep);
/* ************************************************************************** */
/*  Child_process.c                                                          */
/* ************************************************************************** */
void	exec_command(t_pipex *pipex, char **argv, char **envp, int an);
void	child_input(char **av, t_pipex *pipex, char **envp);
void	child_output(char **av, t_pipex *pipex, char **envp);
void	prep_command(char *cmd, t_pipex *pipex);
void	check_access(t_pipex *pipex);
#endif