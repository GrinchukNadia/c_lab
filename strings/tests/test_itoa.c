#include "libft.h"
#include "test.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	func_name("ft_itoa");
	char *res0;
	res0 = ft_itoa(109);
	check_str("positive nbr", res0, "109");
	
	char *res1;
	res1 = ft_itoa(-42);
	check_str("negative nbr", res1, "-42");

	char *res2;
	res2 = ft_itoa(INT_MAX);
	check_str("max nbr", res2, "2147483647");

	char *res3;
	res3 = ft_itoa(INT_MIN);
	check_str("min nbr", res3, "-2147483648");

	char *res4;
	res4 = ft_itoa(7);
	check_str("single digit", res4, "7");

	char *res5;
	res5 = ft_itoa(-7);
	check_str("negative single digit", res5, "-7");

	char *res6;
	res6 = ft_itoa(0);
	check_str("zero", res6, "0");

	char *res7;
	res7 = ft_itoa(1000);
	check_str("trailing zeros", res7, "1000");

	char *res8;
	res8 = ft_itoa(4020);
	check_str("zeros between digits", res8, "4020");

	free(res0);
	free(res1);
	free(res2);
	free(res3);
	free(res4);
	free(res5);
	free(res6);
	free(res7);
	free(res8);

	return (test_result());
}