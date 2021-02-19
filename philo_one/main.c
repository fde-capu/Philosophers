/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:25:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/19 11:50:11 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	printf("\n"		"::: Philosophers :: Philo One :::"	"\n"	\
					":::::: fde-capu ::::: 2102 ::::::"	"\n\n");
	quotes(random_int(0, 51));
	printf("\n\n");
	if (validate_args(argc, argv))
	{
		philo_init_all();
		if (STRATEGY == 2)
			init_semaphore();
		strategy_log();
		printf("Initial state:\n");
		//philo_log_all();
		g_a_m_e_o_v_e_r = 0;
		game_start();
		philo_destroy_all(g_philo_one);
		if (STRATEGY == 2)
			destroy_semaphore();
		printf("\n");
		return (0);
	}
	else
	{
		printf("\n>>> Invalid arguments.\n");
		quotes(1);
		return (-1);
	}
}
