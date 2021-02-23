/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:27:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/23 11:52:46 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	raise_forks(t_philo *p)
{
	pthread_mutex_lock(p->fork_l);
	if (g_a_m_e_o_v_e_r)
		return ;
	p->fork_l_bol = 1;
	fork_log("%d has taken the fork on the left.\n", p);
	pthread_mutex_lock(p->fork_r);
	if (g_a_m_e_o_v_e_r)
		return ;
	p->fork_r_bol = 1;
	fork_log("%d has taken the fork on the right.\n", p);
	return ;
}

void	lower_forks(t_philo *p)
{
	pthread_mutex_unlock(p->fork_l);
	p->fork_l_bol = 0;
	pthread_mutex_unlock(p->fork_r);
	p->fork_r_bol = 0;
	return ;
}
