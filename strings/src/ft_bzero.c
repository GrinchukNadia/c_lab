/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 17:59:29 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/09/17 17:59:32 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Sets the first n bytes of memory to zero.
 */
#include "strings.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
