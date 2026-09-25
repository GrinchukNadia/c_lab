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

static size_t	substr_len(size_t sz_s, unsigned int start, size_t len)
{
	size_t	sz_c;

	if (start >= sz_s)
		return (0);
	if (sz_s - start < len)
		sz_c = sz_s - start;
	else
		sz_c = len;
	return (sz_c);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sz_s;
	size_t	sz_c;
	char	*res;

	i = 0;
	sz_s = ft_strlen(s);
	sz_c = substr_len(sz_s, start, len);
	res = malloc(sz_c + 1);
	if (!res)
		return (NULL);
	while (i < sz_c)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
