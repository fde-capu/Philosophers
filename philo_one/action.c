/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:57:43 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/19 17:38:17 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		action_think(t_philo *p)
{
	if (g_a_m_e_o_v_e_r)
		return (0);
	change_state(p, STATE_THINK);
	usleep(TICK_MICRO_S);
	return (action_eat(p));
}

int		action_eat(t_philo *p)
{
	if (g_a_m_e_o_v_e_r)
		return (0);
	raise_forks(p);
	change_state(p, STATE_EAT);
	if(eat_or_die(p))
		return (-1);
//	usleep(mili_to_micro(g_time_to_eat));
	p->meals++;
	lower_forks(p);
	return (action_nap(p));
}

int		action_nap(t_philo *p)
{
	if (g_a_m_e_o_v_e_r)
		return (0);
	change_state(p, STATE_NAP);
	if(nap_or_die(p))
		return (-1);
//	usleep(mili_to_micro(g_time_to_nap));
	return (action_think(p));
}

int		am_i_stuffed(t_philo *p)
{
	if (p->meals >= g_end_game)
	{
		change_state(p, STATE_STUFFED);
		return (1);
	}
	return (0);
}
