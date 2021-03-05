/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:51:45 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/05 14:10:19 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			change_state(t_philo *p, int state)
{
	if (state == p->state)
		return ;
	pthread_mutex_lock(&g_lock_print);
	if (g_a_m_e_o_v_e_r)
	{
		pthread_mutex_unlock(&g_lock_print);
		return ;
	}
	p->state = state;
	p->last_change = g_clock;
	if (state == STATE_EAT)
		p->last_meal = g_clock;
	philo_log_direct(p);
	pthread_mutex_unlock(&g_lock_print);
	return ;
}

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

t_philo			*philo_init(int id)
{
	t_philo		*p;
	const char	*tmp;

	p = calloc(1, sizeof(t_philo));
	p->id = id;
	p->state = STATE_OUT;
	tmp = ft_itoa(p->id);
	p->sem_name = ft_strcat("philo_clock_sem_", tmp);
	free((void *)tmp);
	if (!(p->my_clock = sem_open(p->sem_name, O_CREAT, 0777, 0)))
		exit(-1);
	free((char *)p->sem_name);
	return (p);
}
