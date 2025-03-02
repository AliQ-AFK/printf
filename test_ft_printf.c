
#include <stdio.h>
#include "ft_printf.h"

// ANSI color codes
#define GREEN   "\033[0;32m"
#define RED     "\033[0;31m"
#define BLUE    "\033[0;34m"
#define YELLOW  "\033[0;33m"
#define RESET   "\033[0m"

// Helper function to compare outputs
void check(int expected, int got)
{
    if (expected == got)
        printf(GREEN "✅ PASS\n" RESET);
    else
        printf(RED "❌ FAIL (Expected %d, Got %d)\n" RESET, expected, got);
}

// Basic tests
void test_easy_cases()
{
    printf(YELLOW "\n==== EASY TEST CASES ====\n" RESET);

    printf(BLUE "Expected: A | Got: " RESET);
    check(printf("A\n"), ft_printf("A\n"));

    printf(BLUE "Expected: Hello | Got: " RESET);
    check(printf("Hello\n"), ft_printf("Hello\n"));

    printf(BLUE "Expected: 42 | Got: " RESET);
    check(printf("%d\n", 42), ft_printf("%d\n", 42));

    printf(BLUE "Expected: %% | Got: " RESET);
    check(printf("%%\n"), ft_printf("%%\n"));
}

// Medium difficulty tests
void test_medium_cases()
{
    printf(YELLOW "\n==== MEDIUM TEST CASES ====\n" RESET);

    printf(BLUE "Expected: Name: Alice, Age: 25 | Got: " RESET);
    check(printf("Name: %s, Age: %d\n", "Alice", 25), ft_printf("Name: %s, Age: %d\n", "Alice", 25));

    printf(BLUE "Expected: ff | Got: " RESET);
    check(printf("%x\n", 255), ft_printf("%x\n", 255));

    printf(BLUE "Expected: FF | Got: " RESET);
    check(printf("%X\n", 255), ft_printf("%X\n", 255));

    printf(BLUE "Expected: 4294967295 | Got: " RESET);
    check(printf("%u\n", 4294967295U), ft_printf("%u\n", 4294967295U));
}

// Hard difficulty tests
void test_hard_cases()
{
    printf(YELLOW "\n==== HARD TEST CASES ====\n" RESET);

    printf(BLUE "Expected: -2147483648 | Got: " RESET);
    check(printf("%d\n", -2147483648), ft_printf("%d\n", -2147483648));

    printf(BLUE "Expected: 2147483647 | Got: " RESET);
    check(printf("%d\n", 2147483647), ft_printf("%d\n", 2147483647));

    printf(BLUE "Expected: (null) | Got: " RESET);
    check(printf("%s\n", (char *)NULL), ft_printf("%s\n", (char *)NULL));

    int a = 42;
    printf(BLUE "Expected: %p | Got: " RESET, (void *)&a);
    check(printf("%p\n", (void *)&a), ft_printf("%p\n", (void *)&a));
}

// Edge cases and weird scenarios
void test_edge_cases()
{
    printf(YELLOW "\n==== EDGE CASES ====\n" RESET);

    printf(BLUE "Expected: Empty String | Got: " RESET);
    check(printf("%s\n", ""), ft_printf("%s\n", ""));

    printf(BLUE "Expected: Just Percent | Got: " RESET);
    check(printf("%%\n"), ft_printf("%%\n"));

    printf(BLUE "Expected: Large number | Got: " RESET);
    check(printf("%d\n", 9223372036854775807), ft_printf("%d\n", 9223372036854775807));

    printf(BLUE "Expected: Mix | Got: " RESET);
    check(printf("%d, %c, %s\n", 42, 'A', "Hello"), ft_printf("%d, %c, %s\n", 42, 'A', "Hello"));
}

// Crazy extreme cases
void test_extreme_cases()
{
    printf(YELLOW "\n==== EXTREME TEST CASES ====\n" RESET);

    char long_str[1001];
    for (int i = 0; i < 1000; i++)
        long_str[i] = 'A';
    long_str[1000] = '\0';

    printf(BLUE "Expected: 1000 A's | Got: " RESET);
    check(printf("%s\n", long_str), ft_printf("%s\n", long_str));

    printf(BLUE "Expected: Lots of arguments | Got: " RESET);
    check(printf("%d %d %d %d %d %d %d %d %d %d\n", 1,2,3,4,5,6,7,8,9,10),
          ft_printf("%d %d %d %d %d %d %d %d %d %d\n", 1,2,3,4,5,6,7,8,9,10));

    int x = 255;
    printf(BLUE "Expected: Mix Everything | Got: " RESET);
    check(printf("Char: %c, String: %s, Int: %d, Hex: %x, Unsigned: %u, Pointer: %p, %%\n",
          'B', "Test", -1234, x, x, (void *)&x),
          ft_printf("Char: %c, String: %s, Int: %d, Hex: %x, Unsigned: %u, Pointer: %p, %%\n",
          'B', "Test", -1234, x, x, (void *)&x));
}

int main()
{
    test_easy_cases();
    test_medium_cases();
    test_hard_cases();
    test_edge_cases();
    test_extreme_cases();
    return 0;
}
