#include "strings.h"
#include "test.h"

int	main(void)
{
	check("lowercase a", ft_isalpha('a'), 1);
	check("lowercase e", ft_isalpha('e'), 1);
	check("lowercase z", ft_isalpha('z'), 1);

	check("uppercase A", ft_isalpha('A'), 1);
	check("uppercase O", ft_isalpha('O'), 1);
	check("uppercase Z", ft_isalpha('Z'), 1);

	check("number 0", ft_isalpha('0'), 0);
	check("number 5", ft_isalpha('5'), 0);
	check("number 9", ft_isalpha('9'), 0);

	check("symbol @", ft_isalpha('@'), 0);
	check("symbol &", ft_isalpha('&'), 0);
	check("symbol /", ft_isalpha('/'), 0);
	return (test_result());
}