/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 07:34:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/24 16:50:01 by fde-capu         ###   ########.fr       */
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
		return (NAP_COL NAP_STRING NON_COL);
	if (state_code == STATE_THINK)
		return (DIE_COL THINK_STRING NON_COL);
	if (state_code == STATE_EAT)
		return (EAT_COL EAT_STRING NON_COL);
	if (state_code == STATE_OUT)
		return (OUT_COL OUT_STRING NON_COL);
	if (state_code == STATE_DEAD)
		return (OUT_COL DEAD_STRING NON_COL);
	return (0);
}

unsigned int	ms_age(struct timeval cron)
{
	struct timeval	now;

	if (gettimeofday(&now, 0))
		exit(-1);
	return (micro_to_mili((now.tv_sec * 1000000 + now.tv_usec) - \
		(cron.tv_sec * 1000000 + cron.tv_usec)));
}
