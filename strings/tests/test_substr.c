#include "strings.h"
#include "test.h"
#include <stdlib.h>

int	main(void)
{
	char str[] = "Hello world";
	char str_1[] = "";
	char *res;

	res = ft_substr(str, 6, 5);
	check_str("normal substring", res, "world");
	
	char *res_1;
	res_1 = ft_substr(str, 6, 0);
	check_str("empty len", res_1, "");

	char *res_2;
	res_2 = ft_substr(str, 0, 11);
	check_str("whole copy", res_2, str);

	char *res_3;
	res_3 = ft_substr(str, 6, 100);
	check_str("len bigger than str", res_3, "world");

	char *res_4;
	res_4 = ft_substr(str, 10, 5);
	check_str("last letter only", res_4, "d");

	char *res_5;
	res_5 = ft_substr(str, 11, 5);
	check_str("start at end of str", res_5, "");

	char *res_6;
	res_6 = ft_substr(str, 100, 5);
	check_str("start 100 away from str", res_6, "");

	char *res_7;
	res_7 = ft_substr(str_1, 4, 5);
	check_str("empty str", res_7, "");

	char *res_8;
	res_8 = ft_substr(str, UINT_MAX, 5);
	check_str("start UINT_MAX", res_8, "");
	
	free(res);
	free(res_1);
	free(res_2);
	free(res_3);
	free(res_4);
	free(res_5);
	free(res_6);
	free(res_7);
	free(res_8);
	return (test_result());
}