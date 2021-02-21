/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:54:55 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/21 16:39:12 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	change_state(t_philo *p, int state)
{
	if ((state == p->state) || (g_a_m_e_o_v_e_r))
		return ;
	p->state = state;
	if (gettimeofday(&p->last_change, 0))
		exit(-1);
	if (state == STATE_EAT)
		if (gettimeofday(&p->last_meal, 0))
			exit(-1);
	philo_log_direct(p);
	return ;
}

int		enough_nap(t_philo *p)
{
	if (ms_age(p->last_change) < g_time_to_nap)
		return (0);
	return (1);
}

int		enough_eat(t_philo *p)
{
	if (ms_age(p->last_meal) < g_time_to_eat)
		return (0);
	return (1);
}

int		game_mode_death(void)
{
	return (!g_end_game);
}

int		game_mode_eat(void)
{
	return (g_end_game);
}
