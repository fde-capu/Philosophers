/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:25:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/02 16:10:08 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*init_play(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->id % 2)
		action_eat(p);
	else
		action_nap(p);
	return (0);
}

void	game_start_thread(void)
{
	int			id;
	pthread_t	philo_thread[g_philo_limit + 1];

	id = 0;
	while (++id <= g_philo_limit)
		pthread_create(&(philo_thread[id]), 0, &init_play, get_philo(id));
	pthread_create(&(philo_thread[0]), 0, &radar, 0);
	pthread_join(philo_thread[0], 0);
	id = 0;
	while (++id <= g_philo_limit)
		pthread_join(philo_thread[id], 0);
	return ;
}

int		main(int argc, char **argv)
{
	g_a_m_e_o_v_e_r = 0;
	if (validate_args(argc, argv))
	{
		philosophers_intro();
		philo_init_all();
		printf("Initial state:\n");
		philo_log_all();
		game_countdown();
		clock_init();
		take_seat_all();
		game_start_thread();
		printf("%06d ", g_clock);
		fflush(stdout);
		philo_destroy_all(g_philo_one);
		game_outro();
		return (0);
	}
	else
	{
		quotes(1);
		printf("\n>>> Invalid arguments.\n");
		return (-1);
	}
}
