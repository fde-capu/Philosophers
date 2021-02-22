/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:11:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/22 09:53:15 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	strategy_init(void)
{
	sem_unlink("/forks");
	if (STRATEGY == STRATEGY_CENTER_FORKS)
		init_semaphore();
	return ;
}

void	strategy_destroy(void)
{
	if (STRATEGY == STRATEGY_CENTER_FORKS)
		destroy_semaphore();
	return ;
}
