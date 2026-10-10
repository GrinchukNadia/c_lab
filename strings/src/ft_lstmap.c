/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:37:02 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/07 14:37:03 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;
	t_list	*new;
	t_list	*new_list;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	copy = lst;
	new_list = NULL;
	while (copy)
	{
		content = f(copy->content);
		new = ft_lstnew(content);
		if (!new)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new);
		copy = copy->next;
	}
	return (new_list);
}
