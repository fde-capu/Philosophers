/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:25:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/22 15:52:15 by fde-capu         ###   ########.fr       */
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
		return (0);
	}
	else
	{
		printf("\n>>> Invalid arguments.\n");
		quotes(1);
		return (-1);
	}
}

void	game_start_process(void)
{
	int		id;
	pid_t	pid;
	t_philo	*p;

	id = 0;
	while (++id <= g_philo_limit)
	{
		pid = fork();
		if (pid < 0)
			exit(-1);
		if (pid == 0)
			break ;
	}
	if (pid == 0)
	{
		p = get_philo(id);
		action_think(p);
		philo_destroy_all(g_philo_one);
		strategy_destroy();
		exit(0);
	}
	pid = waitpid(0, NULL, 0);
	kill(0, SIGTERM);
	game_outro();
	return ;
}

void	game_start_thread(void)
{
	int			id;
	pthread_t	philo_thread[g_philo_limit + 1];
	t_philo		*p;

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
	{
		p = get_philo(id);
		pthread_mutex_unlock(p->fork_l);
		pthread_mutex_unlock(p->fork_r);
		pthread_join(philo_thread[id], 0);
	}
	game_outro();
	return ;
}

void	game_start(void)
{
	game_countdown();
	take_seat_all();
	if (STRATEGY != STRATEGY_PROCESSES)
		game_start_thread();
	else
		game_start_process();
	return ;
}
