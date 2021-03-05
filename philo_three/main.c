/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:25:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/05 15:59:06 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		play_process(int id)
{
	t_philo			*p;
	int				*radar_arg;
	pthread_t		health_check;
	pthread_t		local_clock;

	radar_arg = malloc(sizeof(int));
	p = get_philo(id);
	*radar_arg = id;
	pthread_create(&(health_check), 0, &radar, radar_arg);
	local_clock = clock_sync_init(p);
	action_think(p);
	game_pid_over();
	pthread_join(health_check, 0);
	free((int *)radar_arg);
	pthread_join(local_clock, 0);
	game_over_event(0);
	philo_pid_destroy_all();
	strategy_destroy();
	return (0);
}

void	game_start_process(void)
{
	int				id;
	pthread_t		local_clock;

	id = 0;
	while (++id <= g_philo_limit)
	{
		if (fork() == 0)
			exit(play_process(id));
	}
	local_clock = clock_init();
	wait_game_end();
	pthread_join(local_clock, 0);
	return ;
}

int		out_error(void)
{
	quotes(1);
	printf("\n>>> Invalid arguments.\n");
	return (-1);
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
		game_pid_over();
		philo_destroy_all(g_philo_one);
		philo_destroy_all_semaphores();
		strategy_destroy();
		game_outro();
		return (0);
	}
	else
		return (out_error());
}
