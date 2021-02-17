/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:57:43 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/16 17:16:14 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	action_think(t_philo *p)
{
	(void)p;
	usleep(mili_to_micro(g_time_to_die));
	return ;
}

void	action_eat(t_philo *p)
{
	(void)p;
	return ;
}

void	action_nap(t_philo *p)
{
	(void)p;
	usleep(mili_to_micro(g_time_to_nap));
	return ;
}

int		raise_forks(t_philo *p)
{
	if (*p->fork_l == ON_TABLE && *p->fork_r == ON_TABLE)
	{
		*p->fork_l = ON_HAND;
		*p->fork_r = ON_HAND;
		return (1);
	}
	return (0);
}

int		lower_forks(t_philo *p)
{
	if (philo_age_last_change(p) < g_time_to_eat)
		return (0);
	*p->fork_l = ON_TABLE;
	*p->fork_r = ON_TABLE;
	return (1);
}
