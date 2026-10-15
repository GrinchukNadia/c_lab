/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:24:57 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/09/17 14:24:59 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Fills the first n bytes of memory with the given byte value.
 */
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		*p = (unsigned char) c;
		i++;
		p++;
	}
	return (s);
}
