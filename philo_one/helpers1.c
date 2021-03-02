/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 07:34:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/02 15:44:06 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				random_int(int min, int max)
{
	long			r;
	struct timeval	current_time;

	if (gettimeofday(&current_time, 0))
		exit(-1);
	r = (current_time.tv_usec % (max - min + 1)) + min;
	return (r);
}

void			str_right(int len, const char *str)
{
	int	i;

	i = 0;
	while (i++ < len - (int)strlen(str))
		write(1, " ", 1);
	spell(str, 0);
	return ;
}

const char		*state_string(int state_code)
{
	if (state_code == STATE_NAP)
		return (NAP_STRING);
	if (state_code == STATE_THINK)
		return (THINK_STRING);
	if (state_code == STATE_EAT)
		return (EAT_STRING);
	if (state_code == STATE_OUT)
		return (OUT_STRING);
	if (state_code == STATE_DEAD)
		return (DEAD_STRING);
	return (0);
}

unsigned int	ms_age(int cron)
{
	return (g_clock - cron);
}
