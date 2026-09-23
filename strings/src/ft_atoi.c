/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:56:02 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/09/22 14:56:05 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Converts the initial part of the string to an integer.
 * Skips leading whitespace and handles one optional '+' or '-' sign.
 * Stops converting at the first non-digit character.
 * Returns the converted integer.
 */
int	is_ws(const char *c)
{
	if (*c == ' ')
		return (1);
	else if (*c >= 9 && *c <= 13)
		return (1);
	return (0);
}

int	is_s(const char *c, int *n, int *s)
{
	if (*c == '+')
	{
		*n = 1;
		*s = 1;
		return (1);
	}
	else if (*c == '-')
	{
		*n = 1;
		*s = -1;
		return (1);
	}
	return (0);
}

void	p_nmr(const char *n, int *res)
{
	while (*n >= '0' && *n <= '9')
	{
		*res = *res * 10 + *n - '0';
		n++;
	}
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	n;
	int	s;

	i = 0;
	res = 0;
	n = 0;
	s = 1;
	while (nptr[i])
	{
		if (!n && is_ws(&nptr[i]))
			i++;
		else if (!n && is_s(&nptr[i], &n, &s))
			i++;
		else
		{
			p_nmr(&nptr[i], &res);
			return (res * s);
		}
	}
	return (0);
}
