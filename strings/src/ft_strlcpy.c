/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 14:06:33 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/09/20 14:06:37 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Copies src to dst within the size limit of dstsize.
 * Copies only as much of src as fits in dst.
 * Adds '\0' if dstsize is greater than 0.
 * Returns the full length of src.
 */
#include <stddef.h>
#include "strings.h"

size_t	ft_strlcpy(char *dst, const char *restrict src, size_t dsize)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (src[i])
	{
		l++;
		i++;
	}
	if (dsize == 0)
		return (l);
	i = 0;
	while (i < dsize - 1 && i < l)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (l);
}
