#include "test.h"
#include <stdio.h>

#define macro1(a, b, c, ...) # __VA_OPT__(a b c)
#define macro2(a, b, c, ...) abc ##, __VA_OPT__(a, b, c)
#define macro3(a, ...) a, __VA_OPT__(1, 2), 3, 4
#define macro4(a, b, ...) __VA_OPT__(#a #b)
#define macro5(a, b, ...) __VA_OPT__(a ## b)

int main(void)
{
    printf(macro1("1", "2", "3", 4));
    char* abc = "%d %d %d %d\n";
    printf(macro2(1, 2, 3, 4));
    printf(macro3(abc, 1, 2));
    printf(macro4(1, 2, 3));
    printf(macro5("Hello ", "world\n", 2));

    SUCCESS;
}
