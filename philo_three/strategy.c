/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:11:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/25 13:38:31 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	change_state(t_philo *p, int state)
{
	if ((state == p->state) || (g_a_m_e_o_v_e_r))
		return ;
	p->state = state;
	if (gettimeofday(&p->last_change, 0))
		exit(-1);
	if (state == STATE_EAT)
		if (gettimeofday(&p->last_meal, 0))
			exit(-1);
	if (g_a_m_e_o_v_e_r)
		return ;
	philo_log_direct(p);
	if (state == STATE_DEAD)
		sem_post(g_someone_is_dead);
	return ;
}

t_philo			*philo_init(int id)
{
	t_philo	*p;

	p = calloc(1, sizeof(t_philo));
	p->id = id;
	p->state = STATE_OUT;
	return (p);
}

void	set_gameover(int foo)
{
	(void)foo;
	g_a_m_e_o_v_e_r = 1;
	return ;
}

void			strategy_init(void)
{
	sem_unlink("/forks");
	if (!(g_center_forks = sem_open("/forks", O_CREAT, 0777, g_philo_limit)))
		exit(-1);
	sem_unlink("/stuffed");
	if (!(g_stuffed_guys = sem_open("/stuffed", O_CREAT, 0777, 0)))
		exit(-1);
	sem_unlink("/alive");
	if (!(g_someone_is_dead = sem_open("/alive", O_CREAT, 0777, 0)))
		exit(-1);
	return ;
}

void			strategy_destroy(void)
{
	sem_post(g_someone_is_dead);
	sem_close(g_center_forks);
	sem_unlink("/forks");
	sem_close(g_stuffed_guys);
	sem_unlink("/stuffed");
	sem_close(g_someone_is_dead);
	sem_unlink("/alive");
	return ;
}
