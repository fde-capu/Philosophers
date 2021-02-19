/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:25:33 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/19 19:17:33 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define STRATEGY		1
# define SHARED_FORKS	1
# define CENTER_FORKS	2
# define COUNT_DOWN		0

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <semaphore.h>
# include <fcntl.h>

# include "structs.h"
# include "fun.h"

# define TRIM_SET	" \t\n\r\v\f"

# define DIE_COL "\x1B[031m"
# define EAT_COL "\x1B[032m"
# define NAP_COL "\x1B[036m"
# define OUT_COL "\x1B[035m"
# define NON_COL "\x1B[0m"

# define STATE_STUFFED	-3
# define STATE_DEAD		-2
# define STATE_OUT		-1
# define STATE_NAP		0
# define STATE_THINK	1
# define STATE_EAT		2

# define TICK_MICRO_S	1000

void			take_seat_all(void);
int				nap_or_die(t_philo *p);
int				eat_or_die(t_philo *p);
void			strategy_init(void);
void			strategy_destroy(void);
int				argn(int arg);
long long		ft_atoi(const char *str);
int				main(int argc, char **argv);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strtrimx(char *s1, char *set);
char			*ft_trim(char *str);
int				ft_isdigit(int c);
int				ft_chrinset(char r, char const *sset);
int				ft_strchrinset(char *t, char const *sset);
int				ft_chrsame(char a, char b);
void			log_args(void);
int				validate_args(int argc, char **argv);
int				random_int(int min, int max);
void			str_right(int len, const char *str);
int				philo_take_seat(t_philo *p);
void			philo_destroy_all(t_philo *p);
void			philo_init_all(void);
t_philo			*philo_init_chain(int id);
void			philo_log(int id);
void			philo_log_direct(t_philo *p);
void			philo_log_all(void);
const char		*state_string(int state_code);
t_philo			*get_philo(int id);
void			philo_link_r(void);
void			philo_destroy(t_philo *p);
const char		*fork_string(t_philo *p, int lr);
void			game_start(void);
void			*init_play(void *arg);
t_philo			*philo_init(int id);
unsigned int	mili_to_micro(unsigned long mili);
int				action_eat(t_philo *p);
int				action_think(t_philo *p);
int				action_nap(t_philo *p);
void			philo_print_age(t_philo *p);
unsigned int	micro_to_mili(long int micro);
void			raise_forks(t_philo *p);
void			lower_forks(t_philo *p);
unsigned int	philo_age_last_change(t_philo *p);
unsigned int	ms_age(struct timeval cron);
int				enough_nap(t_philo *p);
int				enough_eat(t_philo *p);
void			change_state(t_philo *p, int state);
int				am_i_dead(t_philo *p);
int				am_i_stuffed(t_philo *p);
void			destroy_semaphore(void);
void			init_semaphore(void);
void			strategy_log();
void			*radar(void *arg);

#endif
