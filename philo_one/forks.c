/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:27:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/22 09:56:08 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	raise_forks(t_philo *p)
{
	if (STRATEGY == STRATEGY_SHARED_FORKS)
	{
		usleep(random_int(0, p->id * 3));
		if (VERBOSE)
			printf("%d locks L %p\n", p->id, p->fork_l);
		pthread_mutex_lock(p->fork_l);
		if (g_a_m_e_o_v_e_r)
			return ;
		p->fork_l_bol = 1;
		if (VERBOSE)
			philo_log_direct(p);
		if (VERBOSE)
			printf("%d took left fork.\n", p->id);
		if (VERBOSE)
			printf("%d locks R %p\n", p->id, p->fork_r);
		pthread_mutex_lock(p->fork_r);
		if (g_a_m_e_o_v_e_r)
			return ;
		p->fork_r_bol = 1;
		if (VERBOSE)
			philo_log_direct(p);
		if (VERBOSE)
			printf("%d took right fork.\n", p->id);
	}
	if (STRATEGY == STRATEGY_CENTER_FORKS)
	{
		if (sem_wait(g_center_forks) != 0)
			exit(-1);
		if (VERBOSE)
			printf("%d took one fork.\n", p->id);
		if (sem_wait(g_center_forks) != 0)
			exit(-1);
		if (VERBOSE)
			printf("%d took another fork.\n", p->id);
	}
	return ;
}

void	lower_forks(t_philo *p)
{
	if (STRATEGY == STRATEGY_SHARED_FORKS)
	{
		if (VERBOSE)
			printf("%d unlocks L %p\n", p->id, p->fork_r);
		pthread_mutex_unlock(p->fork_l);
		p->fork_l_bol = 0;
		if (VERBOSE)
			philo_log_direct(p);
		if (VERBOSE)
			printf("%d drop left fork.\n", p->id);
		if (VERBOSE)
			printf("%d unlocks R %p\n", p->id, p->fork_r);
		pthread_mutex_unlock(p->fork_r);
		p->fork_r_bol = 0;
		if (VERBOSE)
			philo_log_direct(p);
		if (VERBOSE)
			printf("%d drop right fork.\n", p->id);
	}
	if (STRATEGY == STRATEGY_CENTER_FORKS)
	{
		sem_post(g_center_forks);
		if (VERBOSE)
			printf("%d drops a fork.\n", p->id);
		sem_post(g_center_forks);
		if (VERBOSE)
			printf("%d drops another fork.\n", p->id);
	}
	return ;
}
