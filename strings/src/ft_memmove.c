/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 15:07:43 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/09/19 15:07:45 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Copies n bytes from src to dest.
 * Handles overlapping memory areas safely.
 */
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;
	size_t				p;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (d > s)
		p = n;
	else
		p = 1;
	while (i < n)
	{
		*(d + p - 1) = *(s + p - 1);
		i++;
		if (d > s)
			p--;
		else
			p++;
	}
	return (dest);
}
