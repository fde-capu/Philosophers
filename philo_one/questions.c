/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   questions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:50:58 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/01 09:52:28 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		eat_or_die(t_philo *p)
{
	while (!(is_game_over()) && !(am_i_dead(p)))
	{
		if (enough_eat(p))
			return (0);
		usleep(TICK);
	}
	lower_forks(p);
	return (1);
}

int		nap_or_die(t_philo *p)
{
	while (!(is_game_over()) && !(am_i_dead(p)))
	{
		if (enough_nap(p))
			return (0);
		usleep(TICK);
	}
	return (1);
}

int		am_i_dead(t_philo *p)
{
	int	age;

	if (is_game_over())
		return (2);
	age = ms_age(p->last_meal);
	if (age > (int)g_time_to_die + EPSILON)
	{
		lower_forks(p);
		change_state(p, STATE_DEAD);
		set_game_over();
		return (1);
	}
	return (0);
}

int		are_we_stuffed(void)
{
	int		id;

	id = 0;
	while (++id <= g_philo_limit)
		if (get_philo(id)->meals < g_end_game)
			return (0);
	set_game_over();
	return (1);
}
