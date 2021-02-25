/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:25:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/25 13:40:45 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	id = 0;
	pid = fork();
	if (pid == 0)
		while (++id <= g_philo_limit)
			sem_wait(g_stuffed_guys);
	else
		sem_wait(g_someone_is_dead);
	kill(0, SIGINT);
	return ;
}

void	game_start(void)
{
	game_countdown();
	take_seat_all();
	game_start_process();
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
		game_start();
		game_outro();
		philo_destroy_all(g_philo_one);
		strategy_destroy();
		return (0);
	}
	else
	{
		quotes(1);
		printf("\n>>> Invalid arguments.\n");
		return (-1);
	}
}
