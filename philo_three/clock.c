/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 09:13:23 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/03 16:02:33 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clock_init(void)
{
	pthread_t		th_clock;

	if (pthread_create(&th_clock, 0, &fn_clock, 0) != 0)
		exit(-1);
	pthread_detach(th_clock);
	return ;
}

void	*fn_clock(void *arg)
{
	struct timeval	now;
	int				sync;
	t_philo			*p;

	(void)arg;
	sync = g_clock;
	if (gettimeofday(&g_init_time, 0))
		exit(-1);
	while (!g_a_m_e_o_v_e_r)
	{
		if (gettimeofday(&now, 0))
			exit(-1);
		g_clock = (((now.tv_sec * 1000) + now.tv_usec / 1000) - \
			((g_init_time.tv_sec * 1000) + g_init_time.tv_usec / 1000));
		while (sync < g_clock)
		{
			sync++;
			p = g_philo_one;
			while (p->id != g_philo_limit)
			{
				sem_post(p->my_clock);
				p = p->l;
			}
			sem_post(p->my_clock);
		}
		usleep(TICK);
	}
	return (0);
}

void	*clock_synchrony(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (!g_a_m_e_o_v_e_r)
	{
		sem_wait(p->my_clock);
		g_clock++;
	}
	return (0);
}

void	clock_sync_init(t_philo *p)
{
	pthread_t	sync;

	g_clock = 0;
	if (pthread_create(&sync, 0, &clock_synchrony, p) != 0)
		exit(-1);
	pthread_detach(sync);
	return ;
}
