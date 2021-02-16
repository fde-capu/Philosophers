/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:25:33 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/16 10:18:17 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

# define TRIM_SET	" \t\n\r\v\f"

# define DIE_COL "\x1B[031m"
# define EAT_COL "\x1B[032m"
# define NAP_COL "\x1B[036m"
# define NON_COL "\x1B[0m"

# define NL	printf("\n");

int			argn(int arg);
long long	ft_atoi(const char *str);
int			main(int argc, char **argv);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strtrimx(char *s1, char *set);
char		*ft_trim(char *str);
int			ft_isdigit(int c);
int			ft_chrinset(char r, char const *sset);
int			ft_strchrinset(char *t, char const *sset);
int			ft_chrsame(char a, char b);
void		log_args(void);
int			validate_args(int argc, char **argv);
void		quote(const char *qt, const char *nm);
void		quotes(int qn);
void		quotes_load_p1(int q);
void		quotes_load_p2(int q);
void		quotes_load_p3(int q);
void		quotes_load_p4(int q);
void		quotes_load_p5(int q);
void		quotes_load_p6(int q);
void		quotes_load_p7(int q);
void		quotes_load_p8(int q);
void		quotes_load_p9(int q);
int			random_int(int min, int max);
void		str_right(int len, const char *str);
void		nxt_state(t_philo *p);
void		philo_destroy_all(t_philo *p);
void		philo_init_all(void);
t_philo		*philo_init_chain(int id);
void		philo_log(int id);
void		philo_log_all(void);
const char	*state_string(int state_code);
t_philo		*get_philo(int id);
void		philo_link_r(void);

#endif
