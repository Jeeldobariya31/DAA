// factorial using recursion
#include <stdio.h>
#include <time.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    clock_t start = clock();
    int result = factorial(n);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Factorial of %d is %d\n", n, result);
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}