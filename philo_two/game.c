/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:51:45 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/26 11:53:10 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	take_seat_all(void)
{
	int			id;
	t_philo		*p;

	id = 0;
	while (++id <= g_philo_limit)
	{
		p = get_philo(id);
		philo_take_seat(p);
	}
	return ;
}

int		philo_take_seat(t_philo *p)
{
	if (p->state == STATE_OUT)
	{
		if (gettimeofday(&p->birth, 0))
			exit(-1);
		if (gettimeofday(&p->last_meal, 0))
			exit(-1);
		printf("Philosopher\t%d\thas taken a sit.\n", p->id);
		return (1);
	}
	return (0);
}

int				is_game_over(void)
{
	int	ret;

	ret = g_a_m_e_o_v_e_r;
	return (ret);
}

void			set_game_over(void)
{
	g_a_m_e_o_v_e_r = 1;
	return ;
}
