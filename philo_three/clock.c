/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 09:13:23 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/01 13:40:37 by fde-capu         ###   ########.fr       */
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
//	struct timeval	era;

	(void)arg;
	while (!g_a_m_e_o_v_e_r)
	{
//		if (gettimeofday(&era, 0))
//			exit(-1);
//		g_clock = micro_to_mili((era.tv_sec * 1000000 + era.tv_usec) - \
//			(g_init_time.tv_sec * 1000000 + g_init_time.tv_usec));
//		printf("gclock %d\n", g_clock);
		usleep(1000);
		g_clock++;
//		printf("%d ", g_clock); fflush(stdout);
	}
	return (0);
}
