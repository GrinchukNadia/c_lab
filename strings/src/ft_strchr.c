/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 13:59:54 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/09/16 13:59:57 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Finds the first occurrence of character c in the string.
 * Returns a pointer to it, or NULL if it is not found.
 */
#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
