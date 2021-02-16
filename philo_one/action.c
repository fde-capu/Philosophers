/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:57:43 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/16 15:03:36 by fde-capu         ###   ########.fr       */
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
	usleep(mili_to_micro(g_time_to_eat));
	return ;
}

void	action_nap(t_philo *p)
{
	(void)p;
	usleep(mili_to_micro(g_time_to_nap));
	return ;
}
