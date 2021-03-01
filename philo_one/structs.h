/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:46:44 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/01 09:20:30 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_philo
{
	int				id;
	int				state;
	int				birth;
	int				last_change;
	int				last_meal;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	int				meals;
	struct s_philo	*l;
	struct s_philo	*r;
}					t_philo;

int					g_argc;
char				**g_argv;
int					g_philo_limit;
unsigned int		g_time_to_die;
unsigned int		g_time_to_eat;
unsigned int		g_time_to_nap;
int					g_end_game;
t_philo				*g_philo_one;
pthread_mutex_t		g_lock_print;
pthread_mutex_t		g_lock_game_over;
int					g_a_m_e_o_v_e_r;
int					g_clock;
struct timeval		g_init_time;

#endif
