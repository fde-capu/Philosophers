/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:27:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/18 09:37:09 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	raise_forks(t_philo *p)
{
//	pthread_mutex_lock(&g_lock);
	*p->fork_l = ON_HAND;
	*p->fork_r = ON_HAND;
//	pthread_mutex_unlock(&g_lock);
	return ;
}

void	lower_forks(t_philo *p)
{
//	pthread_mutex_lock(&g_lock);
	*p->fork_l = ON_TABLE;
	*p->fork_r = ON_TABLE;
//	pthread_mutex_unlock(&g_lock);
	return ;
}

int		forks_available(t_philo *p)
{
	if (*p->fork_l == ON_TABLE \
	&& *p->fork_r == ON_TABLE)
		return (1);
	return (0);
}
