#include "libft.h"
#include "test.h"
#include <stdlib.h>

int	main(void)
{
	func_name("ft_lstnew");
	char 	*str = "hello";
	t_list	*nn;
	t_list *nn1;

	nn = ft_lstnew(str);
	check("node with str allocated", nn != NULL, 1);
	if (nn != NULL)
	{
		check("new node with str", nn->content == str, 1);
		check("new node, next null", nn->next == NULL, 1);
	}

	nn1 = ft_lstnew(NULL);
	check("node with null allocated", nn1 != NULL, 1);
	if (nn1 != NULL)
	{
		check("new node with null", nn1->content == NULL, 1);
		check("new node with null, next null", nn1->next == NULL, 1);
	}

	free(nn);
	free(nn1);
	return (test_result());
}