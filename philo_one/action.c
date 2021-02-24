/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:57:43 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/24 14:44:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		action_think(t_philo *p)
{
	change_state(p, STATE_THINK);
	return (action_eat(p));
}

int		action_eat(t_philo *p)
{
	raise_forks(p);
	change_state(p, STATE_EAT);
	if (eat_or_die(p))
		return (-1);
	p->meals++;
	lower_forks(p);
	if ((game_mode_eat()) && (are_we_stuffed()))
		return (-1);
	return (action_nap(p));
}

int		action_nap(t_philo *p)
{
	change_state(p, STATE_NAP);
	if (nap_or_die(p))
		return (-1);
	return (action_think(p));
}

void	*radar(void *arg)
{
	(void)arg;
	while (!(are_we_dead()))
		usleep(TICK_MICRO_S);
	return (0);
}
