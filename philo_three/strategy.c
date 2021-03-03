/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:11:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/03 17:45:56 by fde-capu         ###   ########.fr       */
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
	return (p);
}

void			game_over_event(int foo)
{
	(void)foo;
	g_a_m_e_o_v_e_r = 1;
	return ;
}

void			strategy_init(void)
{
	struct sigaction	action;

	sem_unlink("/forks");
	if (!(g_center_forks = sem_open("/forks", O_CREAT, 0777, g_philo_limit)))
		exit(-1);
	sem_unlink("/stuffed");
	if (!(g_stuffed_guys = sem_open("/stuffed", O_CREAT, 0777, 0)))
		exit(-1);
	sem_unlink("/alive");
	if (!(g_someone_is_dead = sem_open("/alive", O_CREAT, 0777, 0)))
		exit(-1);
	memset(&action, 0, sizeof(struct sigaction));
	action.sa_handler = game_over_event;
	sigaction(SIGINT, &action, NULL);
	return ;
}

void			strategy_destroy(void)
{
	pthread_mutex_unlock(&g_lock_print);
	sem_close(g_center_forks);
	sem_unlink("/forks");
	sem_close(g_stuffed_guys);
	sem_unlink("/stuffed");
	sem_close(g_someone_is_dead);
	sem_unlink("/alive");
	return ;
}
