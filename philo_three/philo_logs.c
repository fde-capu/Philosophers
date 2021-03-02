/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_logs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:11:08 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/02 18:30:19 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		philo_log_all(void)
{
	int	id;

	id = 0;
	while (++id <= g_philo_limit)
		philo_log_direct(get_philo(id));
	return ;
}

void		philo_log_direct(t_philo *p)
{
	if (game_mode_eat() && (p->state == STATE_NAP))
		printf("%06d %d %s Meals: %d\n", p->last_change, p->id, \
			state_string(p->state), p->meals);
	else
		printf("%06d %d %s\n", p->last_change, p->id, \
			state_string(p->state));
	return ;
}

void		strategy_log(void)
{
	printf(STRAT_DESC);
	printf("\n");
	return ;
}
