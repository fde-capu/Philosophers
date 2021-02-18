/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:51:45 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/18 09:48:05 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*init_play(void *arg)
{
	t_philo	*p;

//	pthread_mutex_lock(&g_lock);
	p = (t_philo *)arg;
	while (1) {
		nxt_state(p);
		if (p->state == STATE_EAT)
			action_eat(p);
		if (p->state == STATE_NAP)
			action_nap(p);
		if (p->state == STATE_THINK)
			action_think(p);
		philo_log_direct(p);
		usleep(TICK_MICRO_S);
		if (am_i_dead(p))
			return (NULL);
	}
//	pthread_mutex_unlock(&g_lock);
	return (NULL);
}

int		am_i_dead(t_philo *p)
{
	if (ms_age(p->last_meal) > g_time_to_eat)
	{
		change_state(p, STATE_DEAD);
		return (1);
	}
	return (0);
}

void	game_start(void)
{
	int				id;
	pthread_t		tid[g_philo_limit + 1];

	game_intro();
//	if (pthread_mutex_init(&g_lock, NULL) != 0)
//		exit(-1);
	id = 1; // 0
//	while (++id <= g_philo_limit)
//	{
		if (pthread_create(&(tid[id]), NULL, \
			&init_play, get_philo(id)) != 0)
			exit(-1);
		pthread_join(tid[id], NULL);
//	}
//	pthread_mutex_destroy(&g_lock);
	printf("\nResult:\n");
	philo_log(id);
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
