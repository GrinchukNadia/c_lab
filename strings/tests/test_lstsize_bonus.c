#include "strings.h"
#include "test.h"
#include <stdlib.h>

int main(void)
{
	int	sz;
	t_list	*h0 = NULL;

	t_list	*h1;
	t_list	*h2;
	char	*s1 = "hello";
	char	*s2 = "world";

	sz = ft_lstsize(h0);
	check("empty linked list", sz, 0);

	h1 = ft_lstnew(s1);
	sz = ft_lstsize(h1);
	check("one el linked list", sz, 1);

	h2 = ft_lstnew(s2);
	ft_lstadd_front(&h1, h2);
	sz = ft_lstsize(h1);
	check("two el linked list", sz , 2);

	free(h1->next);
	free(h1);
	return (test_result());
}