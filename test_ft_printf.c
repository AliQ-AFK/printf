#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void test_char()
{
    int ret1, ret2;
    
    ret1 = printf("Real:    [%c]\n", 'A');
    ret2 = ft_printf("Custom:  [%c]\n", 'A');
    printf("Return Values -> Real: %d | Custom: %d\n\n", ret1, ret2);
}

void test_string()
{
    int ret1, ret2;
    
    ret1 = printf("Real:    [%s]\n", "Hello, World!");
    ret2 = ft_printf("Custom:  [%s]\n", "Hello, World!");
    printf("Return Values -> Real: %d | Custom: %d\n\n", ret1, ret2);
}

void test_int()
{
    int ret1, ret2;

    ret1 = printf("Real:    [%d]\n", 42);
    ret2 = ft_printf("Custom:  [%d]\n", 42);
    printf("Return Values -> Real: %d | Custom: %d\n\n", ret1, ret2);
}

int main()
{
    test_char();
    test_string();
    test_int();
    return 0;
}
