/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:25:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/20 19:52:36 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*init_play(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	action_think(p);
	return (0);
}

int		main(int argc, char **argv)
{
	philosophers_intro();
	if (validate_args(argc, argv))
	{
		philo_init_all();
		strategy_init();
		printf("Initial state:\n");
		philo_log_all();
		g_a_m_e_o_v_e_r = 0;
		game_start();
		philo_destroy_all(g_philo_one);
		strategy_destroy();
		printf("\n");
		return (0);
	}
	else
	{
		printf("\n>>> Invalid arguments.\n");
		quotes(1);
		return (-1);
	}
}

void	game_start(void)
{
	int			id;
	pthread_t	philo_thread[g_philo_limit + 1];
	t_philo		*p;

	game_countdown();
	take_seat_all();
	id = 0;
	while (++id <= g_philo_limit)
	{
		p = get_philo(id);
		if (pthread_create(&(philo_thread[id]), 0, \
			&init_play, p) != 0)
			exit(-1);
	}
	if (pthread_create(&(philo_thread[0]), 0, \
		&radar, 0) != 0)
		exit(-1);
	pthread_join(philo_thread[0], 0);
	id = 0;
	while (++id <= g_philo_limit)
		pthread_cancel(philo_thread[id]);
	game_outro();
	return ;
}

void	*radar(void *arg)
{
	(void)arg;
	while (!g_a_m_e_o_v_e_r)
		usleep(TICK_MICRO_S);
	return (0);
}
