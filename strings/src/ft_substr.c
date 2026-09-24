/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:29:49 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/09/24 10:29:52 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "strings.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sz_s;
	char	*res;
	size_t	i;
	size_t	y;
	size_t	sz_c;

	sz_s = ft_strlen(s);
	i = 0;
	y = 0;
	sz_c = 0;
	if (len == 0 || sz_s < start)
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (sz_s - start < len)
		sz_c = sz_s - start;
	else
		sz_c = len;
	res = malloc(sz_c + 1);
	if (!res)
		return (NULL);
	y = start;
	while (i < sz_c)
	{
		res[i] = s[y];
		i++;
		y++;
	}
	res[i] = '\0';
	return (res);
}
