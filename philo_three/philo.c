/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 07:39:53 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/05 14:12:50 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	philo_destroy_all(t_philo *p)
{
	if (p->l->id == 1)
	{
		philo_destroy(p);
		return ;
	}
	philo_destroy_all(p->l);
	philo_destroy(p);
	g_philo_one = 0;
	return ;
}

t_philo	*philo_init_chain(int id)
{
	t_philo	*p;

	p = philo_init(id);
	if (id == 1)
		g_philo_one = p;
	if (id == g_philo_limit)
		p->l = g_philo_one;
	else
		p->l = philo_init_chain(id + 1);
	return (p);
}

void	philo_destroy(t_philo *p)
{
	sem_post(p->my_clock);
	sem_close(p->my_clock);
	//sem_unlink(p->sem_name);
	//free((char *)p->sem_name);
	//	p->sem_name = 0;
	free(p);
	p = 0;
	return ;
}

void	philo_destroy_all_semaphores(void)
{
	int			id;
	char		*tmp;

	id = 0;
	while (++id <= g_philo_limit)
	{
		tmp = ft_itoa(id);
		tmp = ft_strcatxr("philo_clock_sem_", tmp);
		sem_unlink(tmp);
		free((void *)tmp);
		//sem_post(p->my_clock);
		//	sem_close(p->my_clock);
		//	sem_unlink(p->sem_name);
		//	free((char *)p->sem_name);
		//	p->sem_name = 0;
	}
	return ;
}

void			philo_pid_destroy_all(void)
{
	int				id;
	t_philo			*p;

	p = g_philo_one;
	if (!p)
		return ;
	id = 0;
	while (++id < g_philo_limit)
	{
		sem_close(p->my_clock);
//		free((char *)p->sem_name);
		//p->sem_name = 0;
		p = p->l;
		free(p->r);
	}
	sem_close(p->my_clock);
	free(p);
	return ;
}
