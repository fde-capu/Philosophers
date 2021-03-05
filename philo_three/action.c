/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:57:43 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/04 22:03:18 by fde-capu         ###   ########.fr       */
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
	stuff_me(p);
	lower_forks(p);
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
	int		id;
	t_philo	*p;

	id = *(int *)arg;
	p = get_philo(id);
	while ((!g_a_m_e_o_v_e_r) && (!(am_i_dead(p))))
		usleep(TICK);
	return (0);
}
