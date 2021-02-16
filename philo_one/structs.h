/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:46:44 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/16 16:05:16 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_philo
{
	int				id;
	int				state;
	struct timeval	timestamp;
	int				*fork_l;
	int				*fork_r;
	struct s_philo	*l;
	struct s_philo	*r;
}					t_philo;

int					g_argc;
char				**g_argv;
int					g_philo_limit;
int					g_time_to_die;
int					g_time_to_eat;
int					g_time_to_nap;
int					g_end_game;
t_philo				*g_philo_one;
pthread_mutex_t		g_lock;
int					g_a_m_e_o_v_e_r;

#endif
