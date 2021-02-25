/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:11:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/24 16:08:39 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_philo			*philo_init(int id)
{
	t_philo	*p;

	p = calloc(1, sizeof(t_philo));
	p->id = id;
	p->state = STATE_OUT;
	return (p);
}

void			strategy_init(void)
{
	sem_unlink("/forks");
	if (!(g_center_forks = sem_open("/forks", O_CREAT, 0777, g_philo_limit)))
		exit(-1);
	return ;
}

void			strategy_destroy(void)
{
	sem_close(g_center_forks);
	sem_unlink("/forks");
	return ;
}
