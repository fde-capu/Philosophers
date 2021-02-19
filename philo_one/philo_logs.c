/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_logs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:11:08 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/19 11:47:47 by fde-capu         ###   ########.fr       */
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

	philo_print_age(p);
	printf("\t%d\t", p->id);
	printf("%s\t", state_string(p->state));
	if (STRATEGY == 1)
		printf("forks: ( %s | %s )\n", \
		fork_string(p->fork_l, p), \
		fork_string(p->fork_r, p));
	if (STRATEGY == 2)
	{
		sem_getvalue(g_middle_forks, &sem_val);
		printf("Forks on table: (%d)\n", sem_val);
	}
	return ;
}

void	strategy_log()
{
	if (STRATEGY == SHARED_FORKS)
		printf("Strategy: PHILO_ONE Shared forks in between.");
	if (STRATEGY == MIDDLE_FORKS)
		printf("Strategy: PHILO_TWO Forks at center of table. (Semaphores.)");
	printf("\n\n");
	return ;
}
