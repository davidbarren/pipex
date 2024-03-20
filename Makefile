# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 14:15:56 by dbarrene          #+#    #+#              #
#    Updated: 2024/03/20 17:06:32 by dbarrene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex

LIBFTPATH = ./libft

LIBFT = $(LIBFTPATH)/libft.a

SRCS = main.c\
arg_checks.c\
errors.c\
parent_process.c\
child_process.c\
helper_funcs.c\



OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(OBJS): $(SRCS)
	cc -Wall -Wextra -Werror -c -g $(@:.o=.c) -o $@

$(NAME): $(LIBFTPATH) $(OBJS)
	make -C $(LIBFTPATH)
	cc -Wall -Wextra -Werror $(SRCS) $(LIBFT) -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFTPATH)
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTPATH)
re: fclean $(NAME)
