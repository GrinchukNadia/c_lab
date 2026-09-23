#include "strings.h"
#include "test.h"
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
	int count = 0;
	int x = 0;

	int *i = ft_calloc(10, sizeof(int));
	check("int, returns address", i != NULL, 1);
	if (i == NULL)
		return (test_result());
	
	while(x < 10)
	{
		if(i[x] != 0)
		count++;
	x++;
	}
	check("all int are 0", count == 0, 1);
	i[0] = 5;
	i[9] = 10;
	check("first el int change", i[0], 5);
	check("last el int change", i[9], 10);
	
	char *c = ft_calloc(10, sizeof(char));
	check("char, returns address", c != NULL, 1);
	if (c == NULL)
	{
		free(i);
		return (test_result());
	}

	x = 0;
	count = 0;
	while(x < 10)
	{
		if (c[x] != '\0')
			count++;
		x++;
	}
	check("all chars are \\0", count == 0, 1);
	c[0] = 'a';
	c[9] = 'b';
	check("first el char change", c[0], 'a');
	check("last el char change", c[9], 'b');

	int *y = ft_calloc(SIZE_MAX / sizeof(int) + 1, sizeof(int));
	check("overflow", y == NULL, 1);

	int *z = ft_calloc(10, 0);

	free(i);
	free(c);
	free(y);
	free(z);
	return (test_result());
}