/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:06:44 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/09/16 15:06:47 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Finds the last occurrence of character c in the string.
 * Returns a pointer to it, or NULL if it is not found.
 */
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*l;

	l = NULL;
	while (*s)
	{
		if (*s == (char)c)
		{
			l = (char *)s;
		}
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else if (l)
		return (l);
	return (NULL);
}
