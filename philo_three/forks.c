/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:27:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/23 14:14:01 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	raise_forks(t_philo *p)
{
	if (sem_wait(g_center_forks) != 0)
		exit(-1);
	fork_log("%d has taken a fork.\n", p);
	if (sem_wait(g_center_forks) != 0)
		exit(-1);
	fork_log("%d has taken another fork.\n", p);
	return ;
}

void	lower_forks(t_philo *p)
{
	sem_post(g_center_forks);
	sem_post(g_center_forks);
	return ;
}
