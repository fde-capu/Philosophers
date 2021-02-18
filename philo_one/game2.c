/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:54:55 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/18 15:25:11 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	change_state(t_philo *p, int state)
{
	p->state = state;
	if (gettimeofday(&p->last_change, 0))
		exit (-1);
	if (state == STATE_EAT)
		if (gettimeofday(&p->last_meal, 0))
			exit (-1);
//	pthread_mutex_lock(&g_lock);
	philo_log_direct(p);
//	pthread_mutex_unlock(&g_lock);
	return ;
}

int		philo_take_seat(t_philo *p)
{
	if (p->state == STATE_OUT)
	{
		if (gettimeofday(&p->birth, 0))
			exit (-1);
		if (gettimeofday(&p->last_meal, 0))
			exit (-1);
		printf("Philosopher\t%d\thas taken a sit.\n", p->id);
		change_state(p, STATE_THINK);
		return (1);
	}
	return (0);
}

int		enough_nap(t_philo *p)
{
	if (ms_age(p->last_change) < g_time_to_nap)
		return (0);
	return (1);
}

int		enough_eat(t_philo *p)
{
	if (ms_age(p->last_change) < g_time_to_eat)
		return (0);
	return (1);
}
