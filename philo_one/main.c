/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:25:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/14 11:18:49 by fde-capu         ###   ########.fr       */
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
		return (0);
	}
	else
	{
		printf("\n>>> Invalid arguments.\n");
		quotes(1);
		return (-1);
	}
}

int		random_int(int min, int max)
{
	long			r;
	struct timeval	current_time;

	r = gettimeofday(&current_time, 0);
	r = (current_time.tv_usec % (max - min + 1)) + min;
	return (r);
}

void	quote(const char *qt, const char *nm)
{
	char	*h;
	char	*s;
	int		i;

	write(1, "\n \"     ", 7);
	h = (char *)qt;
	s = h;
	while (*s)
	{
		h = s;
		while (*s && s - h != 40)
			s++;
		while (*s && *s != ' ')
			s++;
		write(1, h, s - h);
		if (!*s++)
			break ;
		write(1, "\n      ", 7);
	}
	i = 51 - (s - h);
	while (--i)
		write(1, " ", 1);
	write(1, "\"\n", 2);
	while (i++ < 54 - (int)strlen(nm))
		write(1, " ", 1);
	printf("- %s", nm);
}
