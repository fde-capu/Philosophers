/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_logs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:11:08 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/23 12:04:10 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	philo_print_age(t_philo *p)
{
	printf("%010d", ms_age(p->birth));
	return ;
}

void	philo_log_all(void)
{
	int	id;

	id = 0;
	while (++id <= g_philo_limit)
		philo_log(id);
	return ;
}

void	philo_log(int id)
{
	t_philo	*p;

	p = get_philo(id);
	philo_log_direct(p);
	return ;
}

void	philo_log_direct(t_philo *p)
{
	pthread_mutex_lock(&g_lock_print);
	if (g_a_m_e_o_v_e_r)
		return ;
	philo_print_age(p);
	printf("\t%d\t", p->id);
	printf("%s ", state_string(p->state));
	printf("( %s | %s )\n", \
	fork_string(p, 0), \
	fork_string(p, 1));
	pthread_mutex_unlock(&g_lock_print);
	return ;
}

void	strategy_log(void)
{
	printf("Strategy: PHILO_ONE\nShared forks in between.");
	printf("\n");
	return ;
}
