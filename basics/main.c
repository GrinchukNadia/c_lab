#include <stdio.h>
#include "strings.h"
#include <stdlib.h>
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
    int fd;
    
    fd = open_tf();
    if(fd != -1)
    {
        ft_putnbr_fd(INT_MIN, fd);
        close(fd);
    }

	unlink("test_output.txt");
    return(0);
}