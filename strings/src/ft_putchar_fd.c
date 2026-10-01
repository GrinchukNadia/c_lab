/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 11:10:50 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/01 11:10:52 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Writes a character to the given file descriptor. */
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
