//
// Created by Eric Houor on 2018/4/23.
//

#include "stdio.h"

#include "recursion.h"


long factorial(long n) {

    long i, fact = 1;

    if (n == 0) {
        return 1;
    }

    for (i = 1; i <= n; i++) {
        fact *= i;
    }

    return fact;
}

int s = 0;
int a[10] = {0};

void fff(int n, int k) {
    int i;
    if (n > 0)
        for (i = n; i >= 1; i--) {
            a[k] = i;
            fff(n - i, k + 1);
        }
    else {
        for (i = 0; i < k; i++) printf("%5d", a[i]);
        printf("\n");
        s++;
    }
}

