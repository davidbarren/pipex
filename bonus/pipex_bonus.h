/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:51:17 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/25 16:01:39 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		**io_fds;
	pid_t	*child_pid;
	char	**paths;
	char	**parsed_cmd;
	int		fok_flag;
	int		xok_flag;
	int		path_index;
	char	**av;
	int		ac;
	int		av_index;
	t_split	*sp;
	int		paths_fl;
	int		parsed_fl;
	int		pipe_fl;
	int		pipecount;
	int		pid_index;
}	t_pipex;

typedef enum e_errco
{
	EMPTY_STR = -1,
	FAKE_CMD = -2,
	NO_PATH = -3,
	BAD_PERM = -4,
	NO_INPUT = -5,
	FAKE_FILE = -6,
	MALLOC_FAIL = -7,
}	t_errco;

/* ************************************************************************** */
/*  Error Handling Functions                                                  */
/* ************************************************************************** */
int		check_args(int ac, t_pipex *pipex);
void	ft_error_exit(int errnum, t_pipex *pipex);
void	get_path(char **envp, t_pipex *pipex);
void	free_split(char **args);
void	free_pipes(int **data);
void	close_pipes(t_pipex *pipex);
/* ************************************************************************** */
/*  Parent_Process.c                                                          */
/* ************************************************************************** */
void	init_forks(char **av, char **envp, t_pipex *pipex);
char	*ft_strjoin_sep(char *s1, char *s2, char sep);
void	open_pipes(t_pipex *pipex);
/* ************************************************************************** */
/*  Child_process.c                                                          */
/* ************************************************************************** */
void	exec_command(t_pipex *pipex, char **argv, char **envp, int an);
void	child_out_bonus(char **av, t_pipex *pipex, char **envp);
void	prep_command(char *cmd, t_pipex *pipex);
void	check_access(t_pipex *pipex);
void	pre_split_checks(char *cmd, t_pipex *pipex);
void	child_in_bonus(char **av, t_pipex *pipex, char **envp);
/* ************************************************************************** */
/*  bonus_utils.c                                                             */
/* ************************************************************************** */
void	child_generic(t_pipex *pipex, char **envp);
void	spawn_children(char **envp, t_pipex *pipex);
#endif
