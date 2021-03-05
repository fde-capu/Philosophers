/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:27:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/05 16:24:41 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*raise_left_fork(void *arg)
{
	t_philo		*p;

	p = (t_philo *)arg;
	pthread_mutex_lock(p->fork_l);
	pthread_mutex_lock(&g_lock_print);
	if (g_a_m_e_o_v_e_r)
	{
		pthread_mutex_unlock(p->fork_l);
		pthread_mutex_destroy(p->fork_l);
		pthread_mutex_unlock(&g_lock_print);
		return (0);
	}
	fork_log("%06d %d " FORK_STRING_L "\n", p);
	pthread_mutex_unlock(&g_lock_print);
	return (0);
}

void	*raise_right_fork(void *arg)
{
	t_philo		*p;

	p = (t_philo *)arg;
	pthread_mutex_lock(p->fork_r);
	pthread_mutex_lock(&g_lock_print);
	if (g_a_m_e_o_v_e_r)
	{
		pthread_mutex_unlock(p->fork_r);
		pthread_mutex_destroy(p->fork_r);
		pthread_mutex_unlock(&g_lock_print);
		return (0);
	}
	fork_log("%06d %d " FORK_STRING_R "\n", p);
	pthread_mutex_unlock(&g_lock_print);
	return (0);
}

void	raise_forks(t_philo *p)
{
	pthread_t	ambidestry[2];

	if ((!g_polite_start) && (!(p->id % 2)))
		while (!g_polite_start)
			usleep(g_philo_limit * 3);
	if (pthread_create(&(ambidestry[0]), 0, &raise_left_fork, p) != 0)
		exit(-1);
	if (pthread_create(&(ambidestry[1]), 0, &raise_right_fork, p) != 0)
		exit(-1);
	pthread_join(ambidestry[0], 0);
	pthread_join(ambidestry[1], 0);
	if (!g_polite_start)
	{
		if (g_philo_limit % 2)
		{
			if (p->id == g_philo_limit)
				g_polite_start = 1;
		}
		else
		{
			if (p->id == g_philo_limit - 1)
				g_polite_start = 1;
		}
	}
	return ;
}

void	lower_forks(t_philo *p)
{
	pthread_mutex_unlock(p->fork_l);
	pthread_mutex_unlock(p->fork_r);
	return ;
}

void	fork_log(const char *pfstr, t_philo *p)
{
	printf(pfstr, g_clock, p->id);
	return ;
}
