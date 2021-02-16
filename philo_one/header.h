/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:25:33 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/16 16:26:37 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

# include "structs.h"

# define TRIM_SET	" \t\n\r\v\f"

# define DIE_COL "\x1B[031m"
# define EAT_COL "\x1B[032m"
# define NAP_COL "\x1B[036m"
# define OUT_COL "\x1B[035m"
# define NON_COL "\x1B[0m"

# define NL	printf("\n");

# define STATE_OUT		-1
# define STATE_NAP		0
# define STATE_THINK	1
# define STATE_EAT		2
# define ON_TABLE		1
# define ON_HAND		0

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
void			quote(const char *qt, const char *nm);
void			quotes(int qn);
void			quotes_load_p1(int q);
void			quotes_load_p2(int q);
void			quotes_load_p3(int q);
void			quotes_load_p4(int q);
void			quotes_load_p5(int q);
void			quotes_load_p6(int q);
void			quotes_load_p7(int q);
void			quotes_load_p8(int q);
void			quotes_load_p9(int q);
int				random_int(int min, int max);
void			str_right(int len, const char *str);
void			nxt_state(t_philo *p);
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
const char		*fork_string(int *fork);
void			game_start(void);
void			game_intro(void);
void			game_outro(void);
void			*round_play(void *arg);
t_philo			*philo_init(int id);
unsigned int	mili_to_micro(unsigned long mili);
void			philosopher_turn(t_philo *p);
void			action_eat(t_philo *p);
void			action_think(t_philo *p);
void			action_nap(t_philo *p);
void			philo_print_age(t_philo *p);
unsigned int	micro_to_mili(long int micro);

#endif
