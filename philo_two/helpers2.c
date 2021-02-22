/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:15:31 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/20 19:56:18 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int	mili_to_micro(unsigned long mili)
{
	return (mili * 1000);
}

unsigned int	micro_to_mili(long int micro)
{
	return (micro / 1000);
}

void			spell(const char *str, int c)
{
	const char	*h;

	h = str;
	if (!c)
		c = INT_MAX;
	while ((*h) && (h - str <= c))
	{
		write(1, h, 1);
		usleep(ANIM_MCS);
		h++;
	}
	return ;
}
