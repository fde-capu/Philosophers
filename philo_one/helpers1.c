/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 07:34:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/16 17:22:30 by fde-capu         ###   ########.fr       */
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

const char	*state_string(int state_code)
{
	if (state_code == STATE_NAP)
		return (NAP_COL "sleeping" NON_COL);
	if (state_code == STATE_THINK)
		return (DIE_COL "thinking" NON_COL);
	if (state_code == STATE_EAT)
		return (EAT_COL "eating  " NON_COL);
	if (state_code == STATE_OUT)
		return (OUT_COL "out     " NON_COL);
	return (0);
}

const char	*fork_string(int *fork)
{
	if (*fork == ON_TABLE)
		return ("table");
	return ("hand ");
}

unsigned int	mili_to_micro(unsigned long mili)
{
	return (mili * 1000);
}

unsigned int	micro_to_mili(long int micro)
{
	return (micro / 1000);
}

unsigned int	ms_age(struct timeval cron)
{
	struct timeval	now;

	if (gettimeofday(&now, NULL))
		exit (-1);
	return(micro_to_mili((now.tv_sec * 1000000 + now.tv_usec) - \
		(cron.tv_sec * 1000000 + cron.tv_usec)));
}
