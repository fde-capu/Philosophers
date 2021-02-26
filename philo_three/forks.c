/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:27:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/26 14:58:01 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	raise_forks(t_philo *p)
{
	if (sem_wait(g_center_forks) != 0)
		exit(-1);
	if (is_game_over())
	{
		sem_post(g_center_forks);
		return ;
	}
	fork_log("%010d %d " FORK_STRING_A "\n", p);
	if (sem_wait(g_center_forks) != 0)
		exit(-1);
	if (is_game_over())
	{
		sem_post(g_center_forks);
		return ;
	}
	fork_log("%010d %d " FORK_STRING_B "\n", p);
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
	pthread_mutex_lock(&g_lock_print);
	if (is_game_over())
	{
		pthread_mutex_unlock(&g_lock_print);
		return ;
	}
	printf(pfstr, ms_age(p->birth), p->id);
	pthread_mutex_unlock(&g_lock_print);
	return ;
}
