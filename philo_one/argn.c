/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:45:10 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/11 14:24:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	argn(int arg)
{
	return (ft_atoi(g_argv[arg]));
}

void	log_args(void)
{
	printf("Number of Philosophers:\t\t%d\n", argn(1));
	printf("Time to die:\t\t\t%d\n", argn(2));
	printf("Time to eat:\t\t\t%d\n", argn(3));
	printf("Time to nap:\t\t\t%d\n", argn(4));
	printf("Must eat this many times:\t%d\n", argn(5));
	return ;
}
