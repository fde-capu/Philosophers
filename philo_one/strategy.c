/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:11:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/01 13:49:41 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			change_state(t_philo *p, int state)
{
	if (state == p->state)
		return ;
	p->state = state;
	p->last_change = g_clock;
	if (state == STATE_EAT)
		p->last_meal = g_clock;
	philo_log_direct(p);
	return ;
}

t_philo			*philo_init(int id)
{
	t_philo	*p;

	p = calloc(1, sizeof(t_philo));
	p->id = id;
	p->state = STATE_OUT;
	p->fork_l = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(p->fork_l, 0) != 0)
		exit(-1);
	return (p);
}

void			set_game_over(void)
{
	g_a_m_e_o_v_e_r = 1;
	return ;
}
