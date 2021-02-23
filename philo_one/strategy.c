/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:11:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/23 14:31:52 by fde-capu         ###   ########.fr       */
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
	if (pthread_mutex_init(p->fork_l, 0) != 0)
		exit(-1);
	return (p);
}

void			*radar(void *arg)
{
	(void)arg;
	while (!g_a_m_e_o_v_e_r)
		usleep(TICK_MICRO_S);
	return (0);
}
