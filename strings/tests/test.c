#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>

static int  total = 0;
static int  failed = 0;
static int  initialized = 0;

int test_result(void)
{
    if(failed > 0)
        return (1);
    return (0);
}
static void    print_summary(void)
{
    printf("\nTests: %d | Passed: %d | Failed: %d", total, total - failed, failed);
    printf("\n---------------------------------------\n");
}

static void init_tests(void)
{
    if(!initialized)
    {
        printf("\n--------------TEST-RESULT--------------\n");
        atexit(print_summary);
        initialized = 1;
    }
}

void    check(char *name, int actual, int expected)
{
    init_tests();
    if (actual == expected)
        printf("\033[32m[OK]\033[0m %s\n", name);
    else
    {
        printf("\033[31m[FAIL]\033[0m %s: expected %d, got %d\n", name, expected, actual);
        failed++;
    }
    total++;
}

void    check_str(char *name, char *actual, char *expected)
{
    init_tests();
    if (!actual || !expected)
    {
        printf("\033[31m[FAIL]\033[0m %s: NULL pointer\n", name);
        failed++;
        total++;
        return;
    }
    while (*actual && *expected)
    {
        if (*actual != *expected)
        {
            printf("\033[31m[FAIL]\033[0m %s: expected %c, got %c\n", name, *expected, *actual);
            failed++;
            total++;
            return;
        }
        actual++;
        expected++;
    }
    if (!*actual && !*expected )
        printf("\033[32m[OK]\033[0m %s\n", name);
    else
    {
        printf("\033[31m[FAIL]\033[0m %s: different string lengths\n", name);
        failed++;
    }
    total++;
}

void	check_fd(const char *name, int fd, const char *expected, size_t len)
{
    char    *buf;
    ssize_t bytes;
    
    init_tests();
    if(lseek(fd, 0, SEEK_SET) == -1)
    {
        printf("\033[31m[FAIL]\033[0m %s: lseek failed\n", name);
        failed++;
        total++;
        return ;
    }

    buf = malloc(len + 1);
    if (!buf)
    {
        printf("\033[31m[FAIL]\033[0m %s: malloc failed\n", name);
        failed++;
        total++;
        return ;
    }
    bytes = read(fd, buf, len);
    if (bytes < 0)
    {
        printf("\033[31m[FAIL]\033[0m %s: read failed\n", name);
        failed++;
        total++;
        free(buf);
        return ;
    }
    else if((size_t)bytes < len)
    {
        printf("\033[31m[FAIL]\033[0m %s: different bytes length\n", name);
        failed++;
        total++;
        free(buf);
        return ;
    }

    size_t  i = 0;
    while(i < len)
    {
        if(buf[i] != expected[i])
        {
           printf("\033[31m[FAIL]\033[0m %s: wrong output\n", name);
            failed++;
            total++;
            free(buf);
            return ; 
        }
        i++;
    }

    char    extra;
    ssize_t extra_bytes;
    extra_bytes = read(fd, &extra, 1);
    if (extra_bytes < 0)
    {
        printf("\033[31m[FAIL]\033[0m %s: read extra bytes failed\n", name);
        failed++;
        total++;
        free(buf);
        return ;
    }
    else if( extra_bytes > 0)
    {
        printf("\033[31m[FAIL]\033[0m %s: output is bigger than expected\n", name);
        failed++;
        total++;
        free(buf);
        return ;
    }
    else
    {
        printf("\033[32m[OK]\033[0m %s\n", name);
        total++;
    }
    free(buf);
}