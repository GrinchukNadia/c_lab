#include "strings.h"
#include "test.h"

int main(void)
{
	int i = 32;
	int m = 0;
	while (i < 127)
	{
		if(!ft_isprint(i))
			m++;
		i++;
	}
	check("all printable", m, 0);
	check("nonprintable below", ft_isprint(31), 0);
	check("nonprintable above", ft_isprint(127), 0);
	check("negative", ft_isprint(-1), 0);
	check("above ascii", ft_isprint(128), 0);
	return (test_result());
}