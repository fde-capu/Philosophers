/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:11:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/06 17:36:21 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			change_state(t_philo *p, int state)
{
	if (state == p->state)
		return ;
	pthread_mutex_lock(&g_lock_print);
	if (g_a_m_e_o_v_e_r)
	{
		pthread_mutex_unlock(&g_lock_print);
		return ;
	}
	p->state = state;
	p->last_change = g_clock;
	if (state == STATE_EAT)
		p->last_meal = g_clock;
	philo_log_direct(p);
	pthread_mutex_unlock(&g_lock_print);
	return ;
}

t_philo			*philo_init(int id)
{
	t_philo	*p;

	p = calloc(1, sizeof(t_philo));
	p->id = id;
	p->state = STATE_OUT;
	return (p);
}

void			strategy_init(void)
{
	sem_unlink("/forks");
	if (!(g_center_forks = sem_open("/forks", O_CREAT, 0777, g_philo_limit)))
		exit(-1);
	sem_unlink("/body_block");
	if (!(g_body_play = sem_open("/body_block", O_CREAT, 0777, 1)))
		exit(-1);
	return ;
}

void			strategy_destroy(void)
{
	sem_close(g_center_forks);
	sem_unlink("/forks");
	sem_close(g_body_play);
	sem_unlink("/body_block");
	return ;
}
