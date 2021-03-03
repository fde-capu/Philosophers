/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:27:03 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/03 15:59:12 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*w;
	long			t;
	char			*r;

	t = n < 0 ? (long)n * -1 : (long)n;
	len = n < 0 ? 2 : 1;
	while (t /= 10)
		len++;
	r = calloc(sizeof(char) * (len + 1), 1);
	if (!r)
		return (0);
	w = r + len;
	*w-- = 0;
	*w = '0';
	if (!n)
		return (r);
	t = n < 0 ? (long)n * -10 : (long)n * 10;
	while (t /= 10)
		*w-- = (t % 10) + '0';
	if (n < 0)
		*w = '-';
	return (r);
}
