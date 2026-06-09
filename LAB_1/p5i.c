// fibonaci using recursion
#include<stdio.h>
#include<time.h>
int fib(int n){
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}

int main(){
    int n;
    clock_t start, end;
    start = clock();
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Fibonacci of %d is %d", n, fib(n));
    end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to calculate fibonacci: %f seconds", time_taken);
    return 0;
}