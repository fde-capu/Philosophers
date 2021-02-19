/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:11:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/19 11:29:31 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		strategy_catch(int strategy_type, t_philo *p)
{
	if (strategy_type == SHARED_FORKS)
		return (strategy_one_should_i_think_further(p));
	if (strategy_type == MIDDLE_FORKS)
		return (strategy_two_should_i_think_further_forks_on_middle(p));
	return (-1);
}

int		strategy_two_should_i_think_further_forks_on_middle(t_philo *p)
{
	if (forks_available_on_middle(p))
		return (0);
	return (1);
}

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
