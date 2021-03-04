/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:25:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/04 08:44:28 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*wait_til_someone_dies(void *arg)
{
	int				id;

	(void)arg;
	id = 0;
	while (++id <= g_philo_limit)
		sem_wait(g_stuffed_guys);
	kill(0, SIGINT);
	return (0);
}

void	*wait_til_all_stuffed(void *arg)
{
	(void)arg;
	pthread_mutex_unlock(&g_lock_ending);
	sem_wait(g_someone_is_dead);
	return (0);
}

void	wait_game_end(void)
{
	pthread_t		two_endings[2];

	if (pthread_create(&(two_endings[0]), 0, &wait_til_someone_dies, 0))
		exit(-1);
	if (pthread_create(&(two_endings[1]), 0, &wait_til_all_stuffed, 0))
		exit(-1);
	pthread_join(two_endings[0], 0);
	pthread_join(two_endings[1], 0);
	kill(0, SIGINT);
	return ;
}

void	game_start_process(void)
{
	int				id;
	pid_t			pid;
	t_philo			*p;
	pthread_t		health_check;
	int				*radar_arg;

	radar_arg = malloc(sizeof(int));
	id = 0;
	while (++id <= g_philo_limit)
	{
		pid = fork();
		if (pid == 0)
		{
			p = get_philo(id);
			*radar_arg = id;
			pthread_create(&(health_check), 0, &radar, radar_arg);
			clock_sync_init(get_philo(id));
			action_think(p);
			id = 0;
			while (++id <= g_philo_limit)
				sem_post(g_stuffed_guys);
			philo_destroy_all(g_philo_one);
			sem_post(g_someone_is_dead);
			pthread_join(health_check, 0);
			free(radar_arg);
			strategy_destroy();
			exit(0);
		}
	}
	clock_init();
	wait_game_end();
	free(radar_arg);
	return ;
}

int		main(int argc, char **argv)
{
	g_a_m_e_o_v_e_r = 0;
	if (validate_args(argc, argv))
	{
		philosophers_intro();
		philo_init_all();
		strategy_init();
		printf("Initial state:\n");
		philo_log_all();
		game_countdown();
		take_seat_all();
		if (gettimeofday(&g_init_time, 0))
			exit(-1);
		game_start_process();
		philo_destroy_all(g_philo_one);
		strategy_destroy();
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
