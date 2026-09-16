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

#include <stddef.h>

char	*ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == c)
		{
			return (str);
		}
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}
