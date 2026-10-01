#include "strings.h"
#include "test.h"
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>

static int open_tf(void)
{
	int fd;
	fd = open("test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	return fd;
}
int main(void)
{
	int test_res;
	int fd;

	fd = open_tf();
	if(fd != -1)
	{
		ft_putchar_fd('A', fd);
		check_fd("output 1 char", fd, "A", 1);
		close(fd);
	}

	fd = open_tf();
	if(fd != -1)
	{
		ft_putchar_fd('\n', fd);
		check_fd("output \\n", fd, "\n", 1);
		close(fd);
	}

	fd = open_tf();
	if(fd != -1)
	{
		ft_putchar_fd(' ', fd);
		check_fd("output space", fd, " ", 1);
		close(fd);
	}

	fd = open_tf();
	if(fd != -1)
	{
		ft_putchar_fd('\0', fd);
		check_fd("output \\0", fd, "\0", 1);
		close(fd);
	}


	test_res = test_result();
	unlink("test_output.txt");
	return (test_res);
}