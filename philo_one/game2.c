/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:54:55 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/16 17:28:46 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		nxt_state(t_philo *p)
{
	if (p->state == STATE_THINK)
	{
		if (raise_forks(p))
		{
			p->state = STATE_EAT;
			return (1);
		}
	}
	if (p->state == STATE_EAT)
	{
		if(lower_forks(p))
		{
			p->state = STATE_NAP;
			return (1);
		}
	}
	if (p->state == STATE_NAP)
	{
		p->state = STATE_THINK;
		return (1);
	}
	if (p->state == STATE_OUT)
	{
		printf("Sitted %d\n", p->id);

		p->state = STATE_THINK;
		if (gettimeofday(&p->timestamp, 0))
			exit (-1);
		return (0);
	}
	return (0);
}
