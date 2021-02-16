/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 07:34:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/16 10:48:40 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	str_right(int len, const char *str)
{
	int	i;

	i = 0;
	while (i++ < len - (int)strlen(str))
		write(1, " ", 1);
	printf("%s", str);
	return ;
}

void	nxt_state(t_philo *p)
{
	if (p->state == STATE_EAT)
	{
		p->state = STATE_NAP;
		return ;
	}
	if (p->state == STATE_DIE)
	{
		p->state = STATE_EAT;
		return ;
	}
	if (p->state == STATE_NAP)
	{
		p->state = STATE_DIE;
		return ;
	}
}

const char	*state_string(int state_code)
{
	if (state_code == STATE_NAP)
		return (NAP_COL "sleeping" NON_COL);
	if (state_code == STATE_DIE)
		return (DIE_COL "thinking" NON_COL);
	if (state_code == STATE_EAT)
		return (EAT_COL "eating" NON_COL);
	return (0);
}

const char	*fork_string(int *fork)
{
	if (*fork == ON_TABLE)
		return ("table");
	return ("hand ");
}
