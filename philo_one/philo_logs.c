/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_logs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:11:08 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/02 15:38:40 by fde-capu         ###   ########.fr       */
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
	int		age;

	age = g_clock;
	pthread_mutex_lock(&g_lock_print);
	if (g_a_m_e_o_v_e_r)
	{
		pthread_mutex_unlock(&g_lock_print);
		return ;
	}
	if (game_mode_eat() && (p->state == STATE_NAP))
		printf("%010d %d %s Meals: %d\n", age, p->id, \
			state_string(p->state), p->meals);
	else
		printf("%010d %d %s\n", age, p->id, \
			state_string(p->state));
	pthread_mutex_unlock(&g_lock_print);
	return ;
}

void		strategy_log(void)
{
	printf(STRAT_DESC);
	printf("\n");
	return ;
}
