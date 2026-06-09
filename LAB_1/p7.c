// Given two integers n and m(m!=0). Find the number closest closest to n and divisible by m. If there are two such integers, print the maximum absolute value.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    printf("Enter two integers n and m (m != 0): ");
    scanf("%d %d", &n, &m);

    int q = n / m;
    int r = n % m;

    int candidate1 = q * m;
    int candidate2 = (q + 1) * m;

    if (abs(n - candidate1) < abs(n - candidate2)) {
        printf("The number closest to %d and divisible by %d is: %d\n", n, m, candidate1);
    } else if (abs(n - candidate1) > abs(n - candidate2)) {
        printf("The number closest to %d and divisible by %d is: %d\n", n, m, candidate2);
    } else {
        printf("The number closest to %d and divisible by %d is: %d\n", n, m, (candidate1 > candidate2) ? candidate1 : candidate2);
    }

    return 0;
}
