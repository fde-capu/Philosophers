/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 09:28:45 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/22 13:18:56 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_semaphore(void)
{
	if (!(g_center_forks = sem_open("/forks", O_CREAT, 0777, g_philo_limit)))
		exit(-1);
	return ;
}

void	destroy_semaphore(void)
{
	sem_close(g_center_forks);
	sem_unlink("/forks");
	return ;
}
