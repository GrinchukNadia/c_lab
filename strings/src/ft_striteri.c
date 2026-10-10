/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 10:13:20 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/01 10:13:21 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Applies a function to each character of a string, modifying it in place. */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
