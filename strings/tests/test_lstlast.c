#include "libft.h"
#include "test.h"
#include <stdlib.h>

int	main(void)
{
	func_name("ft_lstlast");
	t_list	*n0 = NULL;
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;
	t_list	*res;
	t_list	*copy;

	char	*str1 = "first";
	char	*str2 = "second";
	char	*str3 = "third";

	res = ft_lstlast(n0);
	check("first node is NULL", res == NULL, 1);

	n1 = ft_lstnew(str1);
	n2 = ft_lstnew(str2);
	n3 = ft_lstnew(str3);

	res = ft_lstlast(n1);
	check("1 el, returns 1 el", res ==n1, 1);
	copy = n1;
	ft_lstadd_front(&n1, n2);
	res = ft_lstlast(n1);
	check("2 el, returns last", res == copy, 1);
	ft_lstadd_front(&n1, n3);
	res = ft_lstlast(n1);
	check("3 el, returns last", res == copy, 1);
	
	free(n1);
	free(n2);
	free(copy);
	return (test_result());
}