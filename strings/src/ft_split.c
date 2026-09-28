/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 10:14:55 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/09/27 10:14:58 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	is_sep(char const *s, char c)
{
	if (*s == c || *s == 0)
		return (1);
	return (0);
}

static	char	**create_arr(char const *s, char c)
{
	int		i;
	int		w;
	char	**res;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (!is_sep(&s[i], c) && is_sep(&s[i + 1], c))
			w++;
		i++;
	}
	res = malloc(sizeof (char *) * (w + 1));
	if (!res)
		return (NULL);
	return (res);
}

static	char	*create_word(char const *s, char c, int *wl)
{
	int		i;
	char	*res;

	*wl = 0;
	i = 0;
	while (!is_sep(&s[i], c))
	{
		(*wl)++;
		i++;
	}
	res = malloc(*wl + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < *wl)
	{
		res[i] = *s;
		s++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	**handle_err(char **res, int res_i)
{
	while (res_i >= 0)
	{
		free (res[res_i]);
		res_i--;
	}
	free (res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		wl;
	int		res_i;
	char	**res;

	i = 0;
	res_i = 0;
	res = create_arr(s, c);
	if (!res)
		return (NULL);
	while (s[i])
	{
		if (!is_sep(&s[i], c))
		{
			res[res_i] = create_word(&s[i], c, &wl);
			if (!res[res_i])
				return (handle_err(res, res_i - 1));
			i += wl;
			res_i++;
		}
		else
			i++;
	}
	res[res_i] = NULL;
	return (res);
}
