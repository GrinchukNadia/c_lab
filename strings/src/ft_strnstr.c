/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 19:30:59 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/09/21 19:31:01 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Searches for the first occurrence of little in big,
 * within the first len characters of big.
 * Returns a pointer to the beginning of the match.
 * Returns big if little is empty, or NULL if no match is found.
 */
#include <stddef.h>

int	cmp_str(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && *little)
	{
		if (*little != *big)
		{
			return (0);
		}
		i++;
		little++;
		big++;
	}
	if (*little)
		return (0);
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!*little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (i < len && big[i])
	{
		if (big[i] == *little)
		{
			if (cmp_str(&big[i], little, len - i))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
