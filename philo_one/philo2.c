/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:24:30 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/22 09:37:44 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_philo			*philo_init(int id)
{
	t_philo	*p;

	p = calloc(1, sizeof(t_philo));
	p->id = id;
	p->state = STATE_OUT;
	p->fork_l = malloc(sizeof(pthread_mutex_t));
	if (STRATEGY == STRATEGY_SHARED_FORKS)
	{
		if (pthread_mutex_init(p->fork_l, 0) != 0)
			exit(-1);
	}
	return (p);
}

void			philo_init_all(void)
{
	philo_init_chain(1);
	philo_link_r();
	return ;
}

t_philo			*get_philo(int id)
{
	t_philo	*p;

	p = g_philo_one;
	while (p->id < id)
		p = p->l;
	return (p);
}

void			philo_link_r(void)
{
	t_philo	*p;

	g_philo_one->r = get_philo(g_philo_limit);
	g_philo_one->fork_r = g_philo_one->r->fork_l;
	p = g_philo_one->l;
	while (1)
	{
		p->r = get_philo(p->id - 1);
		p->fork_r = p->r->fork_l;
		p = p->l;
		if (p->id == 1)
			break ;
	}
	return ;
}

unsigned int	philo_age_last_change(t_philo *p)
{
	return (ms_age(p->last_change));
}
