/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 09:05:38 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/09/21 09:05:41 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *restrict src, size_t dsize)
{
	size_t	i;
	size_t	l;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (src[x])
		x++;
	while (dst[i] && i < dsize)
		i++;
	l = x + i;
	if (i == dsize || x == 0)
		return (l);
	while (i < dsize - 1 && src[y])
	{
		dst[i] = src[y];
		i++;
		y++;
	}
	dst[i] = '\0';
	return (l);
}
