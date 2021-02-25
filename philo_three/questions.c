/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   questions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:50:58 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/25 18:49:50 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		eat_or_die(t_philo *p)
{
	while (!(is_game_over()) && !(am_i_dead(p)))
	{
		if (enough_eat(p))
			return (0);
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
	}
	return (1);
}

int		are_we_dead(void)
{
	int	id;

	id = 0;
	while (++id <= g_philo_limit)
		if (am_i_dead(get_philo(id)))
			return (1);
	return (0);
}

int		am_i_dead(t_philo *p)
{
	if (is_game_over())
		return (2);
	if (ms_age(p->last_meal) >= g_time_to_die)
	{
		lower_forks(p);
		change_state(p, STATE_DEAD);
		set_game_over();
		return (1);
	}
	return (0);
}

int		stuff_me(t_philo *p)
{
	p->meals++;
	if (p->meals != g_end_game)
		return (0);
	p->stuffed = 1;
	sem_post(g_stuffed_guys);
	return (1);
}
