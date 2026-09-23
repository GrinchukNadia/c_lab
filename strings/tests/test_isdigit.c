#include "strings.h"
#include "test.h"

int main(void)
{
	int m = 0;
	int i = 0;
	check("0", ft_isdigit('0') != 0, 1);
	check("1", ft_isdigit('1') != 0, 1);
	check("2", ft_isdigit('2') != 0, 1);
	check("3", ft_isdigit('3') != 0, 1);
	check("4", ft_isdigit('4') != 0, 1);
	check("5", ft_isdigit('5') != 0, 1);
	check("6", ft_isdigit('6') != 0, 1);
	check("7", ft_isdigit('7') != 0, 1);
	check("8", ft_isdigit('8') != 0, 1);
	check("9", ft_isdigit('9') != 0, 1);
	while(i < '0')
	{
		if(ft_isdigit(i))
			m++;
		i++;
	}
	check("before 0", m == 0, 1);
	i = ':';
	m = 0;
	while(i <= 127)
	{
		if(ft_isdigit(i))
			m++;
		i++;
	}
	check("after 9", m == 0, 1);

	return (test_result());
}