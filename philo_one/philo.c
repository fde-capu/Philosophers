/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 07:39:53 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/19 19:14:05 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	philo_destroy_all(t_philo *p)
{
	if (p->l->id == 1)
	{
		philo_destroy(p);
		return ;
	}
	philo_destroy_all(p->l);
	philo_destroy(p);
	return ;
}

t_philo	*philo_init_chain(int id)
{
	t_philo	*p;

	p = philo_init(id);
	if (id == 1)
		g_philo_one = p;
	if (id == g_philo_limit)
		p->l = g_philo_one;
	else
		p->l = philo_init_chain(id + 1);
	return (p);
}

void	philo_destroy(t_philo *p)
{
	free(p->fork_l);
	free(p);
	return ;
}

int		eat_or_die(t_philo *p)
{
	while (!(am_i_dead(p)))
	{
		usleep(TICK_MICRO_S);
		if (enough_eat(p))
			return (0);
	}
	return (1);
}

int		nap_or_die(t_philo *p)
{
	while (!(am_i_dead(p)))
	{
		usleep(TICK_MICRO_S);
		if (enough_nap(p))
			return (0);
	}
	return (1);
}

int		am_i_dead(t_philo *p)
{
	if (ms_age(p->last_meal) > g_time_to_die)
	{
		change_state(p, STATE_DEAD);
		g_a_m_e_o_v_e_r = 1;
		return (1);
	}
	return (0);
}
