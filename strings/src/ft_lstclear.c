/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 13:39:31 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/06 13:39:33 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*copy;

	if (!lst || !*lst)
		return ;
	while ((*lst))
	{
		copy = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = copy;
	}
}
