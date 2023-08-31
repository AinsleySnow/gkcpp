#include "test.h"
#include <stdio.h>

#define PRINT(...) printf(__VA_ARGS__)
#define PRINTF(format, ...) printf(format __VA_OPT__(,) __VA_ARGS__)

#define VARIADIC1(...) printf(# __VA_ARGS__)
#define VARIADIC2(...) printf(a##__VA_ARGS__)

int main()
{
    PRINT("%d %d\n", 1, 2);
    PRINT("Hello world!\n");
    PRINTF("%d %d\n", 1, 2);
    PRINTF("Hello world!\n");

    VARIADIC1(1, 2, 3\n);

    char* ac = "%d %d\n";
    int b = 1;
    VARIADIC2(c, b, 3);

    SUCCESS;
}
