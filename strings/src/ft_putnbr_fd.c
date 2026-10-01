/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 17:27:31 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/01 17:27:32 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Writes an integer to the given file descriptor. */
#include <unistd.h>

static void	write_nbr(long n, int fd)
{
	char	c;

	if (n > 9)
		write_nbr(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nc;

	nc = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nc *= -1;
	}
	write_nbr(nc, fd);
}
