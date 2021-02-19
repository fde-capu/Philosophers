/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:51:45 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/18 16:55:15 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*init_play(void *arg)
{
	t_philo	*p;

	while (!g_a_m_e_o_v_e_r) {
		pthread_mutex_lock(&g_lock);
		p = (t_philo *)arg;
		if (p->state == STATE_EAT)
			action_eat(p);
		if (p->state == STATE_NAP)
			action_nap(p);
		if (p->state == STATE_THINK)
			action_think(p);
		if (!g_end_game && am_i_dead(p))
			g_a_m_e_o_v_e_r = 1;
		pthread_mutex_unlock(&g_lock);
		usleep(TICK_MICRO_S);
	}
	return (0);
}

int		am_i_dead(t_philo *p)
{
	if (ms_age(p->last_meal) > g_time_to_die)
	{
		change_state(p, STATE_DEAD);
		return (1);
	}
	return (0);
}

int		am_i_stuffed(t_philo *p)
{
	if (p->meals >= g_end_game)
	{
		change_state(p, STATE_STUFFED);
		return (1);
	}
	return (0);
}

void	take_seat_all(void)
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

void	game_start(void)
{
	int			id;
	pthread_t	tid[g_philo_limit + 1];
	t_philo		*p;

	game_intro();
	take_seat_all();
	if (pthread_mutex_init(&g_lock, 0) != 0)
		exit(-1);
	id = 0;
	while (++id <= g_philo_limit)
	{
		p = get_philo(id);
		if (pthread_create(&(tid[id]), 0, \
			&init_play, p) != 0)
			exit(-1);
	}
	while (!g_a_m_e_o_v_e_r)
		usleep(TICK_MICRO_S);
	id = 0;
	while (++id <= g_philo_limit)
	{
		pthread_join(tid[id], 0);
	}
	pthread_mutex_destroy(&g_lock);
	game_outro();
	return ;
}

void	game_intro(void)
{
	printf("\nGame starts: 3 ");
	//fflush(stdout);
	//sleep(1);
	//printf("\b\b2 ");
	//fflush(stdout);
	//sleep(1);
	printf("\b\b1 ");
	fflush(stdout);
	//sleep(1);
	printf("\b\bnow!\n\n");
	fflush(stdout);
	return ;
}

void	game_outro(void)
{
	printf("\nGAME OVER\n\n");
	fflush(stdout);
//	sleep(1);
	return ;
}
