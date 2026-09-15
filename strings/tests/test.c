#include <stdio.h>
#include <stdlib.h>

static int  total = 0;
static int  failed = 0;
static int  initialized = 0;

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
        printf("[OK] %s\n", name);
    else
    {
        printf("[FAIL] %s: expected %d, got %d\n", name, expected, actual);
        failed++;
    }
    total++;
}

void    check_str(char *name, char *actual, char *expected)
{
    init_tests();
    if (!actual || !expected)
    {
        printf("[FAIL] %s: NULL pointer\n", name);
        failed++;
        total++;
        return;
    }
    while (*actual && *expected)
    {
        if (*actual != *expected)
        {
            printf("[FAIL] %s: expected %c, got %c\n", name, *expected, *actual);
            failed++;
            total++;
            return;
        }
        actual++;
        expected++;
    }
    if (!*actual && !*expected )
        printf("[OK] %s\n", name);
    else
    {
        printf("[FAIL] %s: different string lengths\n", name);
        failed++;
    }
    total++;
}