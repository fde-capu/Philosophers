/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   questions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:50:58 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/05 16:29:20 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		eat_or_die(t_philo *p)
{
	while ((!g_a_m_e_o_v_e_r) && !(am_i_dead(p)))
	{
		if (ms_age(p->last_meal) >= g_time_to_eat)
			return (0);
		usleep(g_philo_limit * 3);
	}
	lower_forks(p);
	return (1);
}

int		nap_or_die(t_philo *p)
{
	while ((!g_a_m_e_o_v_e_r) && !(am_i_dead(p)))
	{
		if (ms_age(p->last_change) >= g_time_to_nap)
			return (0);
		usleep(g_philo_limit * 3);
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
	if (g_a_m_e_o_v_e_r)
		return (2);
	if (ms_age(p->last_meal) >= g_time_to_die + (g_philo_limit / 5))
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
