# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 14:15:56 by dbarrene          #+#    #+#              #
#    Updated: 2024/03/25 14:58:29 by dbarrene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex

CC	= cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
OBJDIR = obj
LIBFTPATH = libft

LIBFT = $(LIBFTPATH)/libft.a

SRCS = $(SRCDIR)/main.c\

#BSRCS = $(SRCDIR)/main_bonus.c

CSRCS = $(SRCDIR)/arg_checks.c\
	$(SRCDIR)/errors.c\
	$(SRCDIR)/parent_process.c\
	$(SRCDIR)/child_process.c\
	$(SRCDIR)/helper_funcs.c\


OBJS= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
#BOBJS= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(BSRCS))
COBJS= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(CSRCS))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJDIR) $(COBJS) $(OBJS)
	@echo $(NAME) is being compiled...
	@$(CC) $(CFLAGS) $(OBJS) $(COBJS) -L$(LIBFTPATH) -lft -o $(NAME)

$(LIBFT):
	@make -C $(LIBFTPATH)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@make -C $(LIBFTPATH) clean
	@rm -rf $(OBJDIR)
	@echo Removed Objs

fclean: clean
	@make -C $(LIBFTPATH) fclean
	@rm -rf $(NAME)
	@echo Removed $(NAME)
re: fclean all
