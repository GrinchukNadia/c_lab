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

#include "strings.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*copy;
	copy = *list;
	if(!copy)
		copy = new;
	while(copy->next)
	{
		copy = copy->next;
		printf("%s, hh", (char *)new->content);
	}
	copy->next = new;
}
