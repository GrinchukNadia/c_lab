#include "strings.h"
#include "test.h"
#include <stdlib.h>

int main(void)
{
	t_list	*head;
	t_list	*new;
	t_list	*copy;

	head = ft_lstnew("head");
	copy = head;
	new = ft_lstnew("new");

	ft_lstadd_back(&head, new);
	check("new added to the end", new == head->next, 1);
	check("head is first, 2 el", copy == head, 1);

	t_list *head_null = NULL;
	t_list *new_null;

	new_null = ft_lstnew("not null");
	ft_lstadd_back(&head_null, new_null);
	check("new is head of empty list", head_null == new_null, 1);
	check("after new head is null", head_null->next == NULL, 1);

	t_list	*h;
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;
	t_list	*c;

	h = ft_lstnew("h");
	n1 = ft_lstnew("n1");
	n2 = ft_lstnew("n2");
	n3 = ft_lstnew("n3");
	c = h;

	ft_lstadd_back(&h, n1);
	ft_lstadd_back(&h, n2);
	ft_lstadd_back(&h, n3);

	check("4 el linked list, head", c == h, 1);
	check("4 el linked list, last", h->next->next->next == n3, 1);
	check("4 el linked list, null after last", n3->next == NULL, 1);

	free(new);
	free(head);
	free(new_null);
	free(n3);
	free(n2);
	free(n1);
	free(h);
	return (test_result());
}