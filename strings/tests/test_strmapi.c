#include "libft.h"
#include "test.h"
#include <stdlib.h>

static	char hide(unsigned int i, char c)
{
	if (i > 4)
		return ('*');
	return (c);
}

static	char move(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}

int main(void)
{
	func_name("ft_strmapi");
	char *res0;
	res0 = ft_strmapi("HelloWorld", hide);
	check_str("normal string", res0, "Hello*****");

	char *res1;
	res1 = ft_strmapi("", hide);
	check_str("empty str", res1, "");

	char *res2;
	res2 = ft_strmapi("Hi", hide);
	check_str("short string", res2, "Hi");

	char *res3;
	res3 = ft_strmapi("abc", move);
	check_str("move letters on n", res3, "bcd");

	char *res4;
	res4 = ft_strmapi("failed func", NULL);
	check("func is NULL", res4 == NULL, 1);

	free(res0);
	free(res1);
	free(res2);
	free(res3);
	return (test_result());
}