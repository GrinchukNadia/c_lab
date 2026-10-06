/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 18:28:34 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/05 18:28:36 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*copy;

	if (!list)
		return ;
	if (!*list)
		*list = new;
	else
	{
		copy = *list;
		while (copy->next)
		{
			copy = copy->next;
		}
		copy->next = new;
	}
}
