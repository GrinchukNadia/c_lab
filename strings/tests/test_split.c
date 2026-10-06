#include "libft.h"
#include "test.h"
#include <stdlib.h>

static void free_res(char **res)
{
	size_t	i = 0;
	while(res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

int main(void)
{
	func_name("ft_split");
	char **res0;
	res0 = ft_split("Hello world", ' ');
	check_str("normal split 1st", res0[0], "Hello");
	check_str("normal split 2nd", res0[1], "world");
	check("normal split last NULL", res0[2] == NULL, 1);

	char **res1;
	res1 = ft_split("Hello", ' ');
	check_str("one word", res1[0], "Hello");
	check("one word, last NULL", res1[1] == NULL, 1);

	char **res2;
	res2 = ft_split("", ' ');
	check("empty str", res2[0] == NULL, 1);

	char **res3;
	res3 = ft_split("  Hello world   ", ' ');
	check_str("1, multiple split char", res3[0], "Hello");
	check_str("2, multiple split char", res3[1], "world");
	check("last NULL, multiple split char", res3[2] == NULL, 1);

	char **res4;
	res4 = ft_split("      ", ' ');
	check("str only from split char", res4[0] == NULL, 1);

	char **res5;
	res5 = ft_split("Hello      world", ' ');
	check_str("1st, multiple split char in the middle", res5[0], "Hello");
	check_str("2nd, multiple split char in the middle", res5[1], "world");
	check("last, multiple split char in the middle", res5[2] == NULL, 1);

	char **res6;
	res6 = ft_split("     Hello", ' ');
	check_str("1st, multiple split char on the begin", res6[0], "Hello");
	check("last, multiple split char on the begin", res6[1] == NULL, 1);

	char **res7;
	res7 = ft_split("Hello      ", ' ');
	check_str("1st, multiple split char on the end", res7[0], "Hello");
	check("last, multiple split char on the end", res7[1] == NULL, 1);

	char **res8;
	res8 = ft_split("Hello", '\0');
	check_str("\\0 char separator", res8[0], "Hello");
	check("\\0 char separator last NULL", res8[1] == NULL, 1);

	free_res(res0);
	free_res(res1);
	free_res(res2);
	free_res(res3);
	free_res(res4);
	free_res(res5);
	free_res(res6);
	free_res(res7);
	free_res(res8);
	return (test_result());
}