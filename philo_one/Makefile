# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 12:58:03 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/18 16:52:27 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NUMB_PHILOS	=	3
TIME_TO_DIE	=	910
TIME_TO_EAT	=	400
TIME_TO_NAP	=	500
EAT_X_TIMES	=	0

NAME		=	round_01_think
CC			=	clang
CCFLAGS		=	-Wall -Werror -Wextra -o0 -g
EXEFLAGS	=	-pthread
SRCS		=	main.c argn.c ft_atoi.c ft_strtrim.c \
	ft_isdigit.c ft_chrinset.c quotes.c quotes2.c \
	helpers1.c philo.c philo2.c game.c action.c game2.c \
	strategy.c forks.c
CCHEADS		=	header.h structs.h
OBJS		=	$(SRCS:.c=.o)
VALGRIND	=	valgrind --leak-check=full --show-leak-kinds=all \
				--track-origins=yes
ARGS		=	$(NUMB_PHILOS) $(TIME_TO_DIE) $(TIME_TO_EAT) \
				$(TIME_TO_NAP) $(EAT_X_TIMES)

name:	all

all:	$(NAME)
	$(CC) $(CCFLAGS) $(EXEFLAGS) $(OBJS) -o $(NAME)

$(NAME):	$(OBJS)

$(OBJS):	%.o : %.c $(CCHEADS)
	$(CC) $(CCFLAGS) -o $@ -c $<

fclean:	clean
	-rm -f $(NAME)

clean:
	-rm -f $(OBJS)

re:		fclean all

t:	all
	-./$(NAME) $(ARGS)

tt:	re t

vv:	re v

v:	all
	$(VALGRIND) ./$(NAME) $(ARGS)
