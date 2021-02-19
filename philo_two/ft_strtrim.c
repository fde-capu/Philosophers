/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:10:36 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/11 13:29:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char		*st_trimstart(char const *s1, char const *set)
{
	char	*r;

	r = (char *)s1;
	while ((*r) && (ft_strchrinset(r, set)))
		r++;
	return (r);
}

static size_t	st_trimlen(char const *s1, char const *set)
{
	size_t	l;
	char	*r;

	r = st_trimstart(s1, set);
	l = 0;
	while (*r)
	{
		r++;
		l++;
	}
	r--;
	while ((l) && (ft_strchrinset(r, set)))
	{
		r--;
		l--;
	}
	return (l);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*m;
	size_t	l;
	char	*w;
	char	*r;

	l = st_trimlen(s1, set);
	m = calloc(l + 1, 1);
	if (!m)
		return (NULL);
	w = m;
	r = st_trimstart(s1, set);
	while ((l) && (*r))
	{
		*w = *r;
		w++;
		r++;
		l--;
	}
	return (m);
}

char			*ft_strtrimx(char *s1, char *set)
{
	char	*trd;

	trd = ft_strtrim(s1, set);
	free(s1);
	return (trd);
}

char			*ft_trim(char *str)
{
	return (ft_strtrimx(str, TRIM_SET));
}
