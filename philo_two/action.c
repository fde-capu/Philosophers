/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:57:43 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/18 16:54:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	action_think(t_philo *p)
{
	if (STRATEGY)
		return ;
	raise_forks(p);
	change_state(p, STATE_EAT);
	action_eat(p);
	return ;
}

void	action_eat(t_philo *p)
{
	if (!enough_eat(p))
		return ;
	p->meals++;
	if (g_end_game && am_i_stuffed(p))
	{
		g_a_m_e_o_v_e_r = 1;
		return ;
	}
	lower_forks(p);
	change_state(p, STATE_NAP);
	action_nap(p);
	return ;
}

void	action_nap(t_philo *p)
{
	if (!enough_nap(p))
		return ;
	change_state(p, STATE_THINK);
	return ;
}
