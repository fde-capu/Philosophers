/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:27:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/21 16:17:09 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	raise_forks(t_philo *p)
{
	if (STRATEGY == SHARED_FORKS)
	{
		if (VERBOSE)
			printf("%d locks L %p\n", p->id, p->fork_l);
		pthread_mutex_lock(p->fork_l);
		if (g_a_m_e_o_v_e_r)
			return ;
		p->fork_l_bol = 1;
		philo_log_direct(p);
		if (VERBOSE)
			printf("%d took left fork.\n", p->id);
		if (VERBOSE)
			printf("%d locks R %p\n", p->id, p->fork_r);
		pthread_mutex_lock(p->fork_r);
		if (g_a_m_e_o_v_e_r)
			return ;
		p->fork_r_bol = 1;
		philo_log_direct(p);
		if (VERBOSE)
			printf("%d took right fork.\n", p->id);
	}
	if (STRATEGY == CENTER_FORKS)
	{
//		pthread_mutex_unlock(&g_lock);
		if (sem_wait(g_center_forks) != 0)
			exit(-1);
//		pthread_mutex_lock(&g_lock);
	}
	return ;
}

void	lower_forks(t_philo *p)
{
	if (STRATEGY == 1)
	{
		if (VERBOSE)
			printf("%d unlocks L %p\n", p->id, p->fork_r);
		pthread_mutex_unlock(p->fork_l);
		if (g_a_m_e_o_v_e_r)
			return ;
		p->fork_l_bol = 0;
		philo_log_direct(p);
		if (VERBOSE)
			printf("%d drop left fork.\n", p->id);
		if (VERBOSE)
			printf("%d unlocks R %p\n", p->id, p->fork_r);
		pthread_mutex_unlock(p->fork_r);
		if (g_a_m_e_o_v_e_r)
			return ;
		p->fork_r_bol = 0;
		philo_log_direct(p);
		if (VERBOSE)
			printf("%d drop right fork.\n", p->id);
	}
	if (STRATEGY == 2)
	{
		sem_post(g_center_forks);
	}
	return ;
}
