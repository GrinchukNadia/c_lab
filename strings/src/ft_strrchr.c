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

char	*ft_strrchr(const char *str, int c)
{
	char	*l;

	l = NULL;
	while (*str)
	{
		if (*str == c)
		{
			l = (char *)str;
		}
		str++;
	}
	if (*str == c)
		return ((char *)str);
	else if (l)
		return (l);
	return (NULL);
}
