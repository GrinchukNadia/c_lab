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

static	int	word_length(char const *s, char c)
{
	int	ws;

	ws = 0;
	while (!is_sep(s, c))
	{
		ws++;
		s++;
	}
	return (ws);
}

static	void	fill_w(char const *s, char *res, int wl)
{
	int	i;

	i = 0;
	while (i < wl)
	{
		*res = *s;
		res++;
		s++;
		i++;
	}
	*res = '\0';
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		w;
	int		wl;
	int		res_i;
	char	**res;

	i = 0;
	w = 0;
	res_i = 0;
	while (s[i])
	{
		if (!is_sep(&s[i], c) && is_sep(&s[i + 1], c))
			w++;
		i++;
	}
	res = malloc(sizeof (char *) * (w + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (!is_sep(&s[i], c))
		{
			wl = word_length(&s[i], c);
			res[res_i] = malloc(wl + 1);
			if (! res[res_i])
				return (NULL);
			fill_w(&s[i], res[res_i], wl);
			i += wl;
			res_i++;
		}
		else
			i++;
	}
	res[res_i] = NULL;
	return (res);
}
