#include "strings.h"
#include "test.h"

static	void hide(unsigned int i, char *c)
{
	if (i > 4)
		*c = '*';
}

static	void move(unsigned int i, char *c)
{
	(void)i;
	*c = *c + 1;
}

int main(void)
{
	char str0[] = "HelloWorld";
	ft_striteri(str0, hide);
	check_str("normal string", str0, "Hello*****");

	char str1[] = "";
	ft_striteri(str1, hide);
	check_str("empty str", str1, "");

	char str2[] = "Hi";
	ft_striteri(str2, hide);
	check_str("short string", str2, "Hi");

	char str3[] = "abc";
	ft_striteri(str3, move);
	check_str("move letters on n", str3, "bcd");

	return (test_result());
}