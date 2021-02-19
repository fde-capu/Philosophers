/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:27:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/19 11:32:25 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	raise_forks(t_philo *p)
{
	if (STRATEGY == SHARED_FORKS)
	{
		*p->fork_l = ON_HAND;
		*p->fork_r = ON_HAND;
	}
	if (STRATEGY == MIDDLE_FORKS)
	{
		pthread_mutex_unlock(&g_lock);
		if (sem_wait(g_middle_forks) != 0)
			exit(-1);
		pthread_mutex_lock(&g_lock);
	}
	return ;
}

void	lower_forks(t_philo *p)
{
	if (STRATEGY == 1)
	{
		*p->fork_l = ON_TABLE;
		*p->fork_r = ON_TABLE;
	}
	if (STRATEGY == 2)
	{
		sem_post(g_middle_forks);
	}
	return ;
}

int		forks_available(t_philo *p)
{
	if (*p->fork_l == ON_TABLE \
	&& *p->fork_r == ON_TABLE)
		return (1);
	return (0);
}

int		forks_available_on_middle(t_philo *p)
{
	int always_true_semaphore_takes_care;

	(void)p;
	return (always_true_semaphore_takes_care = 1);
}
