/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 09:19:32 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/01 09:19:34 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Applies a function to each character and returns a newly allocated string. */
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			sz;
	char			*res;
	unsigned int	i;

	i = 0;
	sz = ft_strlen(s);
	res = malloc(sz + 1);
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
