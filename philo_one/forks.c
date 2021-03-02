/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:27:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/02 15:11:21 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*raise_left_fork(void *arg)
{
	t_philo		*p;

	p = (t_philo *)arg;
	pthread_mutex_lock(p->fork_l);
	if (g_a_m_e_o_v_e_r)
	{
		pthread_mutex_unlock(p->fork_l);
		pthread_mutex_destroy(p->fork_l);
		return (0);
	}
	fork_log("%010d %d " FORK_STRING_L "\n", p);
	return (0);
}

void	*raise_right_fork(void *arg)
{
	t_philo		*p;

	p = (t_philo *)arg;
	pthread_mutex_lock(p->fork_r);
	if (g_a_m_e_o_v_e_r)
	{
		pthread_mutex_unlock(p->fork_r);
		pthread_mutex_destroy(p->fork_r);
		return (0);
	}
	fork_log("%010d %d " FORK_STRING_R "\n", p);
	return (0);
}

void	raise_forks(t_philo *p)
{
	pthread_t	ambidestry[2];

	if (pthread_create(&(ambidestry[0]), 0, &raise_left_fork, p) != 0)
		exit(-1);
	if (pthread_create(&(ambidestry[1]), 0, &raise_right_fork, p) != 0)
		exit(-1);
	pthread_join(ambidestry[0], 0);
	pthread_join(ambidestry[1], 0);
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
	int	age;

	age = ms_age(p->birth);
	pthread_mutex_lock(&g_lock_print);
	if (g_a_m_e_o_v_e_r)
	{
		pthread_mutex_unlock(&g_lock_print);
		return ;
	}
	printf(pfstr, age, p->id);
	pthread_mutex_unlock(&g_lock_print);
	return ;
}
