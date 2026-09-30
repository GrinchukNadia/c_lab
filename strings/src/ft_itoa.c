/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 11:00:52 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/09/29 11:00:55 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	void	count_size(long nc, int *sz)
{
	if (nc == 0)
		*sz = 1;
	else
	{
		while (nc > 0)
		{
			*sz = *sz + 1;
			nc /= 10;
		}
	}
}

static	void	fill_str(int i, long n, char *res)
{
	if (n > 9)
	{
		fill_str(i - 1, n / 10, res);
	}
	res[i] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	long	nc;
	int		sz;
	char	*res;

	sz = 0;
	if (n < 0)
	{
		nc = n;
		nc *= -1;
		sz++;
	}
	else
		nc = n;
	count_size(nc, &sz);
	res = malloc(sz + 1);
	if (!res)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	fill_str(sz - 1, nc, res);
	res[sz] = '\0';
	return (res);
}
