/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:25:33 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/11 16:09:51 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

# define TRIM_SET	" \t\n\r\v\f"

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
int			validate_args(void);
void		quote(const char *qt, const char *nm);

#endif
