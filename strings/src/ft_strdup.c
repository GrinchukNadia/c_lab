/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:11:52 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/09/14 14:12:05 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Creates a new allocated copy of the string.
 * The returned string must be freed by the caller.
 */
#include "strings.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		length;
	char	*dup;
	int		i;

	i = 0;
	length = ft_strlen(src);
	dup = malloc(length + 1);
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
