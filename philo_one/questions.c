/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   questions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:50:58 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/21 16:13:01 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		eat_or_die(t_philo *p)
{
	while (!(am_i_dead(p)))
	{
		usleep(TICK_MICRO_S);
		if (enough_eat(p))
			return (0);
	}
	return (1);
}

int		nap_or_die(t_philo *p)
{
	while (!(am_i_dead(p)))
	{
		usleep(TICK_MICRO_S);
		if (enough_nap(p))
			return (0);
	}
	return (1);
}

int		am_i_dead(t_philo *p)
{
	if (ms_age(p->last_meal) > g_time_to_die)
	{
		change_state(p, STATE_DEAD);
		g_a_m_e_o_v_e_r = 1;
		return (1);
	}
	return (0);
}

int		am_i_stuffed(t_philo *p)
{
	if (p->meals >= g_end_game)
	{
		change_state(p, STATE_STUFFED);
		g_a_m_e_o_v_e_r = 1;
		return (1);
	}
	return (0);
}
