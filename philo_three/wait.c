/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:04:38 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/06 18:26:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*wait_til_all_stuffed(void *arg)
{
	int				id;

	(void)arg;
	id = 0;
	while (++id <= g_philo_limit)
		sem_wait(g_stuffed_guys);
	g_a_m_e_o_v_e_r = 1;
	pthread_mutex_lock(&g_lock_print);
	printf(ALL_STUFFED, g_clock, g_end_game);
	return (0);
}

void	*wait_til_someone_dies(void *arg)
{
	(void)arg;
	sem_wait(g_someone_is_dead);
	return (0);
}

void	wait_game_end(void)
{
	pthread_t		two_endings;

	if (game_mode_death())
	{
		if (pthread_create(&(two_endings), 0, &wait_til_someone_dies, 0))
			exit(-1);
	}
	else
	{
		if (pthread_create(&(two_endings), 0, &wait_til_all_stuffed, 0))
			exit(-1);
	}
	pthread_join(two_endings, 0);
	kill(0, SIGINT);
	return ;
}
