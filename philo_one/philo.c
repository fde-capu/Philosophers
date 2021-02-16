/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 07:39:53 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/16 10:29:50 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_philo	*philo_init(int id)
{
	t_philo	*p;
	
	p = calloc(1, sizeof(t_philo));
	p->id = id;
	p->state = STATE_DIE;
	p->fork_l = malloc(sizeof(int));
	*p->fork_l = 1;
	return (p);
}

void	philo_destroy_all(t_philo *p)
{
	if (p->l->id == 1)
	{
		philo_destroy(p);
		return ;
	}
	philo_destroy_all(p->l);
	philo_destroy(p);
	return ;
}

t_philo	*philo_init_chain(int id)
{
	t_philo	*p;

	p = philo_init(id);
	if (id == 1)
		g_philo_one = p;
	if (id == g_philo_limit)
	{
		p->l = g_philo_one;
		return (p);
	}
	else
		p->l = philo_init_chain(id + 1);
	return (p);
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
	printf("Philosopher %d\t", id);
	printf("%s\n", state_string(get_philo(id)->state));
	return ;
}
