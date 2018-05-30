#include <stdio.h>

#include "recursion.h"

int main() {

    long n = 6;

    printf("%ld的阶乘为(非递归方法): %ld.\n", n, factorial(n));

    printf("%ld的阶乘为(递归方法): %ld.\n", n, recursion_factorial(n));

    int x, y, z, s = 0;

    for (x = 1; x <= n; x++)
        for (y = 1; y <= n; y++)
            for (z = 1; z <= n; z++)
                if (x < y && y < z) {
                    s++;
                    printf("%5d%5d%5d\n", x, y, z);
                }
    printf("s=%d\n", s);


    fff(5, 0);


    return 0;
}