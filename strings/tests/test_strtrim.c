#include "strings.h"
#include "test.h"
#include <stdlib.h>

int	main(void)
{
	char *str1;
	str1 = ft_strtrim("abcHelloabc", "abc");
	check_str("normal trim", str1, "Hello");
	
	char *str2;
	str2 = ft_strtrim("abcHellocba", "abc");
	check_str("mixed set", str2, "Hello");

	char *str3;
	str3 = ft_strtrim("abcHello", "abc");
	check_str("trim only on the start", str3, "Hello");

	char *str4;
	str4 = ft_strtrim("Helloabc", "abc");
	check_str("trim only on the end", str4, "Hello");

	char *str5;
	str5 = ft_strtrim("abcHello abc worldabc", "abc");
	check_str("set in the middle", str5, "Hello abc world");

	char *str6;
	str6 = ft_strtrim("Hello", "abc");
	check_str("nothing to trim", str6, "Hello");

	char *str7;
	str7 = ft_strtrim("abcHello", "");
	check_str("empty set", str7, "abcHello");

	char *str8;
	str8 = ft_strtrim("", "abc");
	check_str("empty string", str8, "");

	char *str9;
	str9 = ft_strtrim("abccbabac", "abc");
	check_str("all char in str are from set", str9, "");

	char *str10;
	str10 = ft_strtrim("   Hello world   ", " ");
	check_str("only 1 set", str10, "Hello world");

	char *str11;
	str11 = ft_strtrim("aaaaaaaaaaaaHelloaaaaaaa", "a");
	check_str("multiple repeated set char", str11, "Hello");

	char *str12;
	str12 = ft_strtrim("abc", "abc");
	check_str("str contains all set", str12, "");
	
	free(str1);
	free(str2);
	free(str3);
	free(str4);
	free(str5);
	free(str6);
	free(str7);
	free(str8);
	free(str9);
	free(str10);
	free(str11);
	free(str12);
	return (test_result());
}