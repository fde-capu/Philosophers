/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:10:43 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/20 11:52:05 by fde-capu         ###   ########.fr       */
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
		spell(h, s - h);
//		write(1, h, s - h);
		if (!*s++)
			break ;
		write(1, "\n      ", 7);
	}
	i = 51 - (s - h);
	while (--i)
		write(1, " ", 1);
	write(1, "\"\n", 2);
	usleep(500000);
	str_right(55, nm);
	printf("\n");
	usleep(2000000);
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

void	spell(const char *str, int c)
{
	const char	*h;

	h = str;
	if (!c)
		c = INT_MAX;
	while ((*h) && (h - str <= c))
	{
		write(1, h, 1);
		usleep(ANIM_MCS);
		h++;
	}
	return ;
}

void	game_outro(void)
{
	printf("\n");
	usleep(ANIM_MCS * 5);
	spell("GAME OVER ", 0);
	usleep(ANIM_MCS);
	printf("\n");
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
