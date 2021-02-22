/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:11:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/22 10:10:48 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	strategy_init(void)
{
	sem_unlink("/forks");
	if ((STRATEGY == STRATEGY_CENTER_FORKS) \
	|| (STRATEGY == STRATEGY_PROCESSES))
		init_semaphore();
	return ;
}

void	strategy_destroy(void)
{
	if ((STRATEGY == STRATEGY_CENTER_FORKS) \
	|| (STRATEGY == STRATEGY_PROCESSES))
		destroy_semaphore();
	return ;
}
