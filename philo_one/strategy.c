/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:11:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/19 08:20:37 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		strategy_one_should_i_think_further(t_philo *p)
{
	if (forks_available(p))
		return (0);
	return (1);
}

int		am_i_dead(t_philo *p)
{
	if (ms_age(p->last_meal) > g_time_to_die)
	{
		change_state(p, STATE_DEAD);
		return (1);
	}
	return (0);
}

int		am_i_stuffed(t_philo *p)
{
	if (p->meals >= g_end_game)
	{
		change_state(p, STATE_STUFFED);
		return (1);
	}
	return (0);
}
