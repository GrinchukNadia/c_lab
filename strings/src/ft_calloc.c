/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 09:57:16 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/09/23 09:57:18 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "strings.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*m;

	if (size != 0 && SIZE_MAX / size < count)
	{
		return (NULL);
	}
	m = malloc(count * size);
	if (!m)
		return (NULL);
	m = ft_memset(m, 0, count * size);
	return (m);
}
