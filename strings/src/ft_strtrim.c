/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 15:50:26 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/09/26 15:50:30 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "strings.h"

static	int	is_set(const char *s, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == *s)
			return (1);
		i++;
	}
	return (0);
}

static	void	fill_arr(char const *s1, char *res, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start < end)
	{
		res[i] = s1[start];
		i++;
		start++;
	}
	res[i] = '\0';
}

static	void	count_end(char const *s1, char const *set, size_t *e, size_t l)
{
	size_t	i;

	i = l;
	while (i > 0)
	{
		if (!is_set(&s1[i - 1], set))
		{
			*e = i;
			break ;
		}
		i--;
	}
}

static	void	count_start(char const *s1, char const *set, size_t *start)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (!is_set(&s1[i], set))
		{
			*start = i;
			break ;
		}
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	start;
	size_t	l;
	char	*res;

	start = 0;
	end = 0;
	l = ft_strlen(s1);
	if (l > 0)
	{
		count_start(s1, set, &start);
		count_end(s1, set, &end, l);
		l = end - start;
	}
	res = malloc(l + 1);
	if (!res)
		return (NULL);
	fill_arr(s1, res, start, end);
	return (res);
}
