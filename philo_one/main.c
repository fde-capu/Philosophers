/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:25:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/11 18:34:14 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	printf("\n"		"::: Philosophers :: Philo One :::"	"\n"	\
					":::::: fde-capu ::::: 2102 ::::::"	"\n\n");
	quotes(0);
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
		printf("\n>>> Invalid arguments.\n");
		quotes(1);
		return (-1);
	}
}

void	quote(const char *qt, const char *nm)
{
	char	*h;
	char	*s;

	write(1, "\n \"\n\n      ", 11);
	h = (char *)qt;
	s = h;
	while (*s)
	{
		h = s;
		while (*s && s - h != 42)
			s++;
		while (*s && *s != ' ')
			s++;
		write(1, h, s - h + 1);
		if (*s)
			s++;
		else
			break ;
		write(1, "\n      ", 7);
	}
	printf("\n                                                           \"\n");
	printf("\n                                           - %s\n\n", nm);
}
