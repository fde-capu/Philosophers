/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 07:39:53 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/20 19:51:31 by fde-capu         ###   ########.fr       */
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
