/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:45:10 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/26 12:47:44 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		argn(int arg)
{
	return (ft_atoi(g_argv[arg]));
}

void	log_args(void)
{
	printf("Number of Philosophers:\t\t%d\n", argn(1));
	printf("Time to " DIE_COL "die" NON_COL ":\t\t\t%d\n", argn(2));
	printf("Time to " EAT_COL "eat" NON_COL ":\t\t\t%d\n", argn(3));
	printf("Time to " NAP_COL "nap" NON_COL ":\t\t\t%d\n", argn(4));
	printf("Game end:\t\t\t");
	if (argn(5))
		printf("%d meals to all.\n", argn(5));
	else
		printf("death match. " DIE_COL "x_x" NON_COL "\n");
	printf("\n");
	return ;
}

int		validate_args(int argc, char **argv)
{
	int	a;

	g_argc = argc;
	g_argv = argv;
	a = 0;
	while (++a && a <= 4)
		if (argn(a) <= 0)
			return (0);
	if (argn(a) < 0)
		return (0);
	g_philo_limit = argn(1);
	if (g_philo_limit <= 1)
		return (0);
	g_time_to_die = argn(2);
	g_time_to_eat = argn(3);
	g_time_to_nap = argn(4);
	g_end_game = argn(5);
	log_args();
	return (1);
}
