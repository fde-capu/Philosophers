/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:11:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/23 14:00:12 by fde-capu         ###   ########.fr       */
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

void	strategy_init(void)
{
	struct sigaction	action;

	sem_unlink("/forks");
	init_semaphore();
	memset(&action, 0, sizeof(struct sigaction));
	action.sa_handler = set_gameover;
	sigaction(SIGTERM, &action, NULL);
	return ;
}

void	strategy_destroy(void)
{
	destroy_semaphore();
	return ;
}
