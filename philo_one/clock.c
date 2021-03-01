/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 09:13:23 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/01 10:00:46 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clock_init(void)
{
	pthread_t	th_clock;

	if (pthread_create(&th_clock, 0, &fn_clock, 0) != 0)
		exit(-1);
	pthread_detach(th_clock);
	return ;
}

void	*fn_clock(void *arg)
{
	(void)arg;
	while (!g_a_m_e_o_v_e_r)
	{
		if (gettimeofday(&g_clock, 0))
			exit(-1);
		usleep(TICK / (g_philo_limit * 2));
	}
	return (0);
}
