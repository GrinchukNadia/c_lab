#include "strings.h"
#include "test.h"
#include <stdlib.h>

int	main(void)
{
	char *w1;
	char *w2;
	char *w3;
	char *w4;
	char *w5;
	char *w6;
	char *w7;
	char *w8;
	w1 = ft_strjoin("Hello ", "world");
	check_str("two strings", w1, "Hello world");

	char s1[] = "";
	char s2[] = "world";
	w2 = ft_strjoin(s1, s2);
	check_str("first is empty", w2, "world");
	check("new memory, first is empty", s2 != w2, 1);

	w3 = ft_strjoin(s2, s1);
	check_str("second is empty", w3, "world");
	check("new memory, second is empty", s2 != w3, 1);

	char s3[] = "";
	w4 = ft_strjoin(s1, s3);
	check_str("both are empty", w4, "");
	check("new memory, both are empty", (s1 != w4) && (s2 != w4), 1);

	w5 = ft_strjoin("    ", "    ");
	check_str("only spaces", w5, "        ");

	w6 = ft_strjoin("0", " - is a number");
	check_str("0 in string", w6, "0 - is a number");

	w7 = ft_strjoin("01234", "56789");
	check_str("numbers", w7, "0123456789");

	w8 = ft_strjoin("a", "b");
	check_str("one char strings", w8, "ab");
	
	free(w1);
	free(w2);
	free(w3);
	free(w4);
	free(w5);
	free(w6);
	free(w7);
	free(w8);
	return (test_result());
}