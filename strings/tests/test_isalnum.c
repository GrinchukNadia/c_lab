#include "strings.h"
#include "test.h"

int main(void)
{
	check("lowercase a", ft_isalnum('a') != 0, 1);
	check("lowercase e", ft_isalnum('e') != 0, 1);
	check("lowercase z", ft_isalnum('z') != 0, 1);

	check("uppercase A", ft_isalnum('A') != 0, 1);
	check("uppercase O", ft_isalnum('O') != 0, 1);
	check("uppercase Z", ft_isalnum('Z') != 0, 1);

	check("number 0", ft_isalnum('0') != 0, 1);
	check("number 5", ft_isalnum('5') != 0, 1);
	check("number 9", ft_isalnum('9') != 0, 1);

	check("symbol @", ft_isalnum('@'), 0);
	check("symbol [", ft_isalnum('['), 0);
	check("symbol `", ft_isalnum('`'), 0);
	check("symbol {", ft_isalnum('{'), 0);
	check("symbol &", ft_isalnum('&'), 0);
	check("symbol /", ft_isalnum('/'), 0);
	check("symbol :", ft_isalnum(':'), 0);
	return (test_result());
}