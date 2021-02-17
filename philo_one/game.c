/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:51:45 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/16 17:28:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	philosopher_turn(t_philo *p)
{
	if (nxt_state(p)) {
		if (gettimeofday(&p->last_change, 0))
			exit (-1);
		if (p->state == STATE_EAT)
			action_eat(p);
		if (p->state == STATE_NAP)
			action_nap(p);
		if (p->state == STATE_THINK)
			action_think(p);
		philo_log_direct(p);
	}
	return ;
}

void	*init_play(void *arg)
{
	t_philo	*p;

	pthread_mutex_lock(&g_lock);
	p = (t_philo *)arg;
	philosopher_turn(p);
	pthread_mutex_unlock(&g_lock);
	return (NULL);
}

void	game_start(void)
{
	int				id;
	pthread_t		tid[g_philo_limit + 1];

	game_intro();
	if (pthread_mutex_init(&g_lock, NULL) != 0)
		exit(-1);
int deb = 4;
	while (!g_a_m_e_o_v_e_r)
	{
		id = 0;
		while (++id <= g_philo_limit)
		{
			if (pthread_create(&(tid[id]), NULL, \
				&init_play, get_philo(id)) != 0)
				exit(-1);
			pthread_join(tid[id], NULL);
		}
//		id = 0;
//		while (++id <= g_philo_limit)
//		{
//		}
if (!--deb) {g_a_m_e_o_v_e_r = 1;}
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
