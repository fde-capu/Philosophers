/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:51:45 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/05 11:11:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			take_seat_all(void)
{
	int			id;
	t_philo		*p;

	id = 0;
	while (++id <= g_philo_limit)
	{
		p = get_philo(id);
		philo_take_seat(p);
	}
	return ;
}

int				philo_take_seat(t_philo *p)
{
	if (p->state == STATE_OUT)
	{
		p->birth = 0;
		p->last_meal = 0;
		printf("Philosopher\t%d\thas taken a sit.\n", p->id);
		return (1);
	}
	return (0);
}

int				game_pid_over(void)
{
	clock_destroy(0);
	philo_pid_destroy_all();
//	strategy_destroy();
	return (0);
}

void	philo_pid_destroy_all(void)
{
	int				id;
	t_philo			*p;

	p = g_philo_one;
	if (!p)
		return ;
	id = 0;
	while (++id < g_philo_limit)
	{
//		free((char *)p->sem_name);
		//p->sem_name = 0;
		p = p->l;
		free(p->r);
	}
	free(p);
	return ;
}
