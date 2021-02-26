/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:25:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/26 17:24:49 by fde-capu         ###   ########.fr       */
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

void	game_start_thread(void)
{
	int			id;
	pthread_t	philo_thread[g_philo_limit + 1];
	t_philo		*p;
	int			once;

	once = 1;
	id = 1;
	while (id <= g_philo_limit)
	{
		p = get_philo(id);
		if (pthread_create(&(philo_thread[id]), 0, &init_play, p) != 0)
			exit(-1);
		id += 2;
		if ((id > g_philo_limit) && (once))
		{
			once = 0;
			usleep(1000);
			id = 2;
		}
	}
	if (pthread_create(&(philo_thread[0]), 0, &radar, 0) != 0)
		exit(-1);
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
		take_seat_all();
		game_start_thread();
		printf("%010d ", ms_age(g_philo_one->birth));
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
