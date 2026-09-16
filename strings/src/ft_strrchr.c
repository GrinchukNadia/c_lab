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

#include <stddef.h>

char	*ft_strrchr(char *str, int c)
{
	char	*l;

	l = NULL;
	while (*str)
	{
		if (*str == c)
		{
			l = str;
		}
		str++;
	}
	if (*str == c)
		return (str);
	else if (l)
		return (l);
	return (NULL);
}
