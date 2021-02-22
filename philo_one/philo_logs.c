/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_logs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:11:08 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/22 09:52:15 by fde-capu         ###   ########.fr       */
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
	int	sem_val;

	pthread_mutex_lock(&g_lock_print);
	if (g_a_m_e_o_v_e_r)
		return ;
	philo_print_age(p);
	printf("\t%d\t", p->id);
	printf("%s ", state_string(p->state));
	if (STRATEGY == STRATEGY_SHARED_FORKS)
		printf("( %s | %s )\n", \
		fork_string(p, 0), \
		fork_string(p, 1));
	if (STRATEGY == STRATEGY_CENTER_FORKS)
	{
		sem_getvalue(g_center_forks, &sem_val);
		printf("Forks on table: (%d)\n", sem_val);
	}
	pthread_mutex_unlock(&g_lock_print);
	return ;
}

void	strategy_log(void)
{
	if (STRATEGY == STRATEGY_SHARED_FORKS)
		printf("Strategy: PHILO_ONE Shared forks in between.");
	if (STRATEGY == STRATEGY_CENTER_FORKS)
		printf("Strategy: PHILO_TWO Forks at center of table. (Semaphores.)");
	printf("\n");
	return ;
}
