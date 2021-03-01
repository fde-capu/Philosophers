/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_logs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:11:08 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/26 14:55:16 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	philo_log_all(void)
{
	int	id;

	id = 0;
	while (++id <= g_philo_limit)
		philo_log(id);
	return ;
}

void		philo_log(int id)
{
	t_philo	*p;

	p = get_philo(id);
	philo_log_direct(p);
	return ;
}

void		philo_log_direct(t_philo *p)
{
	int		age;

	age = ms_age(p->birth);
	pthread_mutex_lock(&g_lock_print);
	if (g_a_m_e_o_v_e_r)
	{
		pthread_mutex_unlock(&g_lock_print);
		return ;
	}
	if (p->state != STATE_NAP)
		printf("%010d %d %s\n", age, p->id, \
			state_string(p->state));
	else
		printf("%010d %d %s Meals: %d\n", age, p->id, \
			state_string(p->state), p->meals);
	pthread_mutex_unlock(&g_lock_print);
	return ;
}

void		strategy_log(void)
{
	printf(STRAT_DESC);
	printf("\n");
	return ;
}
