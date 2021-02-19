/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:10:43 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/19 11:36:22 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	str_right(55, nm);
}
