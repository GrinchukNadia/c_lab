/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 13:36:07 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/04 13:36:10 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	int	sz;

	sz = 0;
	while (lst)
	{
		sz++;
		lst = lst->next;
	}
	return (sz);
}
