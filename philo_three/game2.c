/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:54:55 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/25 11:32:13 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		enough_nap(t_philo *p)
{
	if (ms_age(p->last_change) < g_time_to_nap)
		return (0);
	return (1);
}

int		enough_eat(t_philo *p)
{
	if (ms_age(p->last_meal) < g_time_to_eat)
		return (0);
	return (1);
}

int		game_mode_death(void)
{
	return (!g_end_game);
}

int		game_mode_eat(void)
{
	return (g_end_game);
}
