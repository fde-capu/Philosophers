/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:27:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/24 14:45:39 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	raise_left_fork(t_philo *p)
{
	pthread_mutex_lock(p->fork_l);
	if (is_game_over())
	{
		pthread_mutex_unlock(p->fork_l);
		pthread_mutex_destroy(p->fork_l);
		return ;
	}
	p->fork_l_bol = 1;
	fork_log("%d has taken the fork on the left.\n", p);
	return ;
}

void	raise_right_fork(t_philo *p)
{
	pthread_mutex_lock(p->fork_r);
	if (is_game_over())
	{
		pthread_mutex_unlock(p->fork_r);
		pthread_mutex_destroy(p->fork_r);
		return ;
	}
	p->fork_r_bol = 1;
	fork_log("%d has taken the fork on the right.\n", p);
	return ;
}

void	raise_forks(t_philo *p)
{
	if (p->id % 2)
	{
		raise_left_fork(p);
		raise_right_fork(p);
	}
	else
	{
		raise_right_fork(p);
		raise_left_fork(p);
	}
	return ;
}

void	lower_forks(t_philo *p)
{
	pthread_mutex_unlock(p->fork_l);
	p->fork_l_bol = 0;
	pthread_mutex_unlock(p->fork_r);
	p->fork_r_bol = 0;
	return ;
}
