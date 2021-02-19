/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:15:31 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/19 08:15:52 by fde-capu         ###   ########.fr       */
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
