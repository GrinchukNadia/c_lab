#include "libft.h"
#include "test.h"
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

static int open_tf(void)
{
	int fd;
	fd = open("test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	return fd;
}

int main(void)
{
	func_name("ft_putnbr_fd");
	int test_res;
	int fd;

	fd = open_tf();
	if(fd != -1)
	{
		ft_putnbr_fd(7, fd);
		check_fd("positive num", fd, "7", 1);
		close(fd);
	}

	fd = open_tf();
	if(fd != -1)
	{
		ft_putnbr_fd(-9, fd);
		check_fd("negative num", fd, "-9", 2);
		close(fd);
	}

	fd = open_tf();
	if(fd != -1)
	{
		ft_putnbr_fd(0, fd);
		check_fd("output 0", fd, "0", 1);
		close(fd);
	}

	fd = open_tf();
	if(fd != -1)
	{
		ft_putnbr_fd(100100, fd);
		check_fd("number with zeros", fd, "100100", 6);
		close(fd);
	}

	fd = open_tf();
	if(fd != -1)
	{
		ft_putnbr_fd(INT_MIN, fd);
		check_fd("min int", fd, "-2147483648", 11);
		close(fd);
	}

	fd = open_tf();
	if(fd != -1)
	{
		ft_putnbr_fd(INT_MAX, fd);
		check_fd("max int", fd, "2147483647", 10);
		close(fd);
	}


	test_res = test_result();
	unlink("test_output.txt");
	return (test_res);
}