/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:57:43 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/22 15:30:16 by fde-capu         ###   ########.fr       */
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
	if (eat_or_die(p))
		return (-1);
	p->meals++;
	lower_forks(p);
	if (am_i_stuffed(p))
		return (-1);
	return (action_nap(p));
}

int		action_nap(t_philo *p)
{
	if (g_a_m_e_o_v_e_r)
		return (0);
	change_state(p, STATE_NAP);
	if (nap_or_die(p))
		return (-1);
	return (action_think(p));
}

void	*radar(void *arg)
{
	(void)arg;
	while (!g_a_m_e_o_v_e_r)
		usleep(TICK_MICRO_S);
	return (0);
}

void	set_gameover(int foo)
{
	(void)foo;
	g_a_m_e_o_v_e_r = 1;
	return ;
}
