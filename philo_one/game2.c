/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:54:55 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/18 10:48:32 by fde-capu         ###   ########.fr       */
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
	return ;
}

int		nxt_state(t_philo *p)
{
	if (p->state == STATE_THINK)
	{
		change_state(p, STATE_EAT);
		return (1);
	}
	if (p->state == STATE_EAT)
	{
		change_state(p, STATE_NAP);
		return (1);
	}
	if (p->state == STATE_NAP)
	{
		change_state(p, STATE_THINK);
		return (1);
	}
	if (p->state == STATE_OUT)
	{
		printf("Philosopher %d has taken a sit.\n", p->id);
		if (gettimeofday(&p->birth, 0))
			exit (-1);
		change_state(p, STATE_THINK);
		return (0);
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
