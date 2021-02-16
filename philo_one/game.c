/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:51:45 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/16 12:49:02 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*round_play(void *arg)
{
	(void)arg;
	return NULL;
}

void	game_start(void)
{
	int			error;
	int			id;
	pthread_t	tid[g_philo_limit + 1];

	game_intro();
	id = 0;
	while (++id <= g_philo_limit)
	{
		error = pthread_create(&(tid[id]), NULL, &round_play, NULL);
		if (error)
			exit(-1);
	}
	id = 0;
	while (++id <= g_philo_limit)
	{
		pthread_join(tid[id], NULL);
	}
	game_outro();
	return ;
}

void	game_intro(void)
{
	printf("\nGame starts: 3 ");
	fflush(stdout);
	sleep(1);
	printf("\b\b2 ");
	fflush(stdout);
	sleep(1);
	printf("\b\b1 ");
	fflush(stdout);
	sleep(1);
	printf("\b\bnow! ");
	fflush(stdout);
	return ;
}

void	game_outro(void)
{
	printf("\n\nGAME OVER\n\n");
	fflush(stdout);
	sleep(1);
	return ;
}
