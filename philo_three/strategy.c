/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:11:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/05 14:43:35 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				game_pid_over(void)
{
	g_a_m_e_o_v_e_r = 1;
	return (0);
}

void			game_over_event(int foo)
{
	int	id;

	(void)foo;
	g_a_m_e_o_v_e_r = 1;
	sem_post(g_someone_is_dead);
	id = 0;
	while (++id <= g_philo_limit)
		sem_post(g_stuffed_guys);
	return ;
}

void			strategy_init(void)
{
	struct sigaction	action;

	sem_unlink("/forks");
	if (!(g_center_forks = sem_open("/forks", O_CREAT, 0777, g_philo_limit)))
		exit(-1);
	sem_unlink("/stuffed");
	if (!(g_stuffed_guys = sem_open("/stuffed", O_CREAT, 0777, 0)))
		exit(-1);
	sem_unlink("/alive");
	if (!(g_someone_is_dead = sem_open("/alive", O_CREAT, 0777, 0)))
		exit(-1);
	memset(&action, 0, sizeof(struct sigaction));
	action.sa_handler = game_over_event;
	sigaction(SIGINT, &action, NULL);
	return ;
}

void			strategy_destroy(void)
{
	pthread_mutex_unlock(&g_lock_print);
	sem_close(g_center_forks);
	sem_unlink("/forks");
	sem_close(g_stuffed_guys);
	sem_unlink("/stuffed");
	sem_close(g_someone_is_dead);
	sem_unlink("/alive");
	return ;
}

void	*radar(void *arg)
{
	int		id;
	t_philo	*p;

	id = *(int *)arg;
	p = get_philo(id);
	while ((!g_a_m_e_o_v_e_r) && (!(am_i_dead(p))))
		usleep(TICK);
	return (0);
}
