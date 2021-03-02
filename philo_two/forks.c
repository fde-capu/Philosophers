/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:27:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/02 18:31:40 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	raise_forks(t_philo *p)
{
	if (sem_wait(g_center_forks) != 0)
		exit(-1);
	pthread_mutex_lock(&g_lock_print);
	if (g_a_m_e_o_v_e_r)
	{
		pthread_mutex_unlock(&g_lock_print);
		sem_post(g_center_forks);
		return ;
	}
	fork_log("%06d %d " FORK_STRING_A "\n", p);
	pthread_mutex_unlock(&g_lock_print);
	if (sem_wait(g_center_forks) != 0)
		exit(-1);
	pthread_mutex_lock(&g_lock_print);
	if (g_a_m_e_o_v_e_r)
	{
		pthread_mutex_unlock(&g_lock_print);
		sem_post(g_center_forks);
		return ;
	}
	fork_log("%06d %d " FORK_STRING_B "\n", p);
	pthread_mutex_unlock(&g_lock_print);
	return ;
}

void	lower_forks(t_philo *p)
{
	(void)p;
	sem_post(g_center_forks);
	sem_post(g_center_forks);
	return ;
}

void	fork_log(const char *pfstr, t_philo *p)
{
	printf(pfstr, g_clock, p->id);
	return ;
}
