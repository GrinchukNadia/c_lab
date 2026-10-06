#include "libft.h"
#include "test.h"
#include <stdlib.h>

int	main(void)
{
	func_name("ft_lstadd_front");
	t_list *head;
	t_list *new;
	t_list *copy;
	
	head = ft_lstnew("h");
	copy = head;
	new = ft_lstnew("new");

	ft_lstadd_front(&head, new);
	check("new is a head", new == head, 1);
	check("old head is second node", copy == new->next, 1);

	t_list *head_null = NULL;
	t_list *new_null;

	new_null = ft_lstnew("not null");
	ft_lstadd_front(&head_null, new_null);
	check("new is head of empty list", head_null == new_null, 1);
	check("old head is null", new_null->next == NULL, 1);

	free(copy);
	free(new);
	free(new_null);
	return (test_result());
}