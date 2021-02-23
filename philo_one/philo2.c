/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:24:30 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/23 11:37:09 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			philo_init_all(void)
{
	philo_init_chain(1);
	philo_link_r();
	return ;
}

t_philo			*get_philo(int id)
{
	t_philo	*p;

	p = g_philo_one;
	while (p->id < id)
		p = p->l;
	return (p);
}

void			philo_link_r(void)
{
	t_philo	*p;

	g_philo_one->r = get_philo(g_philo_limit);
	g_philo_one->fork_r = g_philo_one->r->fork_l;
	p = g_philo_one->l;
	while (1)
	{
		p->r = get_philo(p->id - 1);
		p->fork_r = p->r->fork_l;
		p = p->l;
		if (p->id == 1)
			break ;
	}
	return ;
}

unsigned int	philo_age_last_change(t_philo *p)
{
	return (ms_age(p->last_change));
}
