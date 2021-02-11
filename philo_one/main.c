/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:25:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/11 15:12:10 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	printf("\n"		"::: Philosophers :: Philo One :::"	"\n"	\
					":::::: fde-capu ::::: 2102 ::::::"	"\n\n");
	g_argc = argc;
	g_argv = argv;
	log_args();
	printf("\n\n");
	if (validate_args())
	{
		return (0);
	}
	else
	{
		printf("\n>>> Invelid arguments.\n>>> Think about it.\n\n");
		return (-1);
	}
}
