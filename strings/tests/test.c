#include <stdio.h>
#include <stdlib.h>

static int  total = 0;
static int  failed = 0;
static int  initialized = 0;

void    print_summary(void)
{
    printf("\nTests: %d | Passed: %d | Failed: %d", total, total - failed, failed);
    printf("\n---------------------------------------\n");
}

void    check(char *name, int actual, int expected)
{
    if(!initialized)
    {
        printf("\n--------------TEST-RESULT--------------\n");
        atexit(print_summary);
        initialized = 1;
    }
    if (actual == expected)
        printf("[OK] %s\n", name);
    else
    {
        printf("[FAIL] %s: expected %d, got %d\n", name, expected, actual);
        failed++;
    }
    total++;
}