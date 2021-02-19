/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:10:43 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/19 17:46:37 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	quote(const char *qt, const char *nm)
{
	char	*h;
	char	*s;
	int		i;

	write(1, "\n \"     ", 7);
	h = (char *)qt;
	s = h;
	while (*s)
	{
		h = s;
		while (*s && s - h != 40)
			s++;
		while (*s && *s != ' ')
			s++;
		write(1, h, s - h);
		if (!*s++)
			break ;
		write(1, "\n      ", 7);
	}
	i = 51 - (s - h);
	while (--i)
		write(1, " ", 1);
	write(1, "\"\n", 2);
	str_right(55, nm);
	printf("\n");
}

void	game_countdown(void)
{
	if (!COUNT_DOWN)
		return ;
	printf("\nGame starts: 3 ");
	fflush(stdout);
	sleep(1);
	printf("\b\b2 ");
	fflush(stdout);
	sleep(1);
	printf("\b\b1 ");
	fflush(stdout);
	sleep(1);
	printf("\b\bnow!\n\n");
	fflush(stdout);
	return ;
}

void	game_outro(void)
{
	printf("\nGAME OVER\n\n");
	fflush(stdout);
	sleep(1);
	return ;
}

void	philosophers_intro(void)
{
	printf("\n"		"::: Philosophers :: Philo One :::"	"\n"	\
					":::::: fde-capu ::::: 2102 ::::::"	"\n");
	strategy_log();
	quotes(random_int(0, 51));
	printf("\n");
	return ;
}
