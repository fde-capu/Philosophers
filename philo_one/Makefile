# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 12:58:03 by fde-capu          #+#    #+#              #
#    Updated: 2021/03/01 11:27:06 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NUMB_PHILOS	=	4
TIME_TO_DIE	=	310
TIME_TO_EAT	=	200
TIME_TO_NAP	=	200
EAT_X_TIMES	=	0

NAME		=	$(shell basename "$(PWD)")
CC			=	clang
CCFLAGS		=	-Wall -Werror -Wextra -g
NMCCFLAGS	=	-pthread
SRCS		=	main.c argn.c ft_atoi.c ft_strtrim.c \
	ft_isdigit.c ft_chrinset.c quotes.c quotes2.c \
	helpers1.c philo.c philo2.c game.c action.c \
	game2.c strategy.c forks.c philo_logs.c helpers2.c \
	fun.c questions.c clock.c
CCHEADS		=	header.h structs.h fun.h
OBJS		=	$(SRCS:.c=.o)
VALGRIND	=	valgrind
VALGFLAGS	=	--leak-check=full \
				--show-leak-kinds=all \
				--track-origins=yes \
				--show-reachable=yes
ARGS		=	$(NUMB_PHILOS) $(TIME_TO_DIE) $(TIME_TO_EAT) \
				$(TIME_TO_NAP) $(EAT_X_TIMES)

name:	all

all:	$(NAME)
	$(CC) $(CCFLAGS) $(NMCCFLAGS) $(OBJS) -o $(NAME)

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

vf:	all
	-$(VALGRIND) $(VALGFLAGS) ./$(NAME) $(ARGS)

v:	all
	-$(VALGRIND) ./$(NAME) $(ARGS)
