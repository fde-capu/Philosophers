/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 09:13:23 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/02 16:04:37 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clock_init(void)
{
	pthread_t		th_clock;

	if (gettimeofday(&g_init_time, 0))
		exit(-1);
	g_clock = 0;
	if (pthread_create(&th_clock, 0, &fn_clock, 0) != 0)
		exit(-1);
	pthread_detach(th_clock);
	return ;
}

void	*fn_clock(void *arg)
{
	struct timeval	now;

	(void)arg;
	while (!g_a_m_e_o_v_e_r)
	{
		if (gettimeofday(&now, 0))
			exit(-1);
		g_clock = (((now.tv_sec * 1000) + now.tv_usec / 1000) - \
			((g_init_time.tv_sec * 1000) + g_init_time.tv_usec / 1000));
		usleep(200);
	}
	return (0);
}
