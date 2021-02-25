/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:46:44 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/25 11:52:54 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_philo
{
	int				id;
	int				state;
	struct timeval	birth;
	struct timeval	last_change;
	struct timeval	last_meal;
	int				meals;
	int				stuffed;
	struct s_philo	*l;
	struct s_philo	*r;
}					t_philo;

int				g_argc;
char			**g_argv;
int				g_philo_limit;
unsigned int	g_time_to_die;
unsigned int	g_time_to_eat;
unsigned int	g_time_to_nap;
int				g_end_game;
t_philo			*g_philo_one;
pthread_mutex_t	g_lock_print;
int				g_a_m_e_o_v_e_r;
sem_t			*g_center_forks;
sem_t			*g_stuffed_guys;
sem_t			*g_someone_is_dead;

#endif
