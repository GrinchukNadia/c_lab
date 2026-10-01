#include "strings.h"
#include "test.h"
#include <fcntl.h>
#include <unistd.h>

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
		ft_putstr_fd("hello", fd);
		check_fd("normal str", fd, "hello", 5);
		close(fd);
	}

	fd = open_tf();
	if(fd != -1)
	{
		ft_putstr_fd("h", fd);
		check_fd("one char", fd, "h", 1);
		close(fd);
	}

	fd = open_tf();
	if(fd != -1)
	{
		ft_putstr_fd("", fd);
		check_fd("empty str", fd, "", 0);
		close(fd);
	}
	
	fd = open_tf();
	if(fd != -1)
	{
		ft_putstr_fd(" ", fd);
		check_fd("space", fd, " ", 1);
		close(fd);
	}
	
	fd = open_tf();
	if(fd != -1)
	{
		ft_putstr_fd("0", fd);
		check_fd("zero as a str", fd, "0", 1);
		close(fd);
	}

	test_res = test_result();

	unlink("test_output.txt");
	return (test_res);
}