# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 12:58:03 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/11 13:55:11 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	round_01_fight
CC			=	clang
CCFLAGS		=	-Wall -Werror -Wextra -o0 -g
SRCS		=	main.c argn.c ft_atoi.c ft_strtrim.c \
	ft_isdigit.c ft_chrinset.c
CCHEADS		=	header.h structs.h
OBJS		=	$(SRCS:.c=.o)
VALGRIND	=	valgrind --leak-check=full --show-leak-kinds=all

name:	all

all:	$(NAME)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

$(NAME):	$(OBJS)

$(OBJS):	%.o : %.c $(CCHEADS)
	$(CC) $(CCFLAGS) -o $@ -c $<

fclean:	clean
	-rm -f $(NAME)

clean:
	-rm -f $(OBJS)

re:		fclean all

t:	re
	-./$(NAME)

v:	re
	$(VALGRIND) ./$(NAME)
