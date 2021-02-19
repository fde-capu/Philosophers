/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:27:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/19 19:28:10 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	raise_forks(t_philo *p)
{
	if (STRATEGY == SHARED_FORKS)
	{
		pthread_mutex_lock(p->fork_l);
		p->fork_l_bol = 1;
		pthread_mutex_lock(p->fork_r);
		p->fork_r_bol = 1;
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
		pthread_mutex_unlock(p->fork_l);
		p->fork_l_bol = 0;
		pthread_mutex_unlock(p->fork_r);
		p->fork_r_bol = 0;
	}
	if (STRATEGY == 2)
	{
		sem_post(g_center_forks);
	}
	return ;
}
