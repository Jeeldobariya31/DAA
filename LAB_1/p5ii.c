// fibonaci without recursion
#include<stdio.h>
#include<time.h>
int fib(int n){
    int a = 0, b = 1, c;
    if(n == 0)
        return a;
    else if(n == 1)
        return b;
    else{
        for(int i = 2; i <= n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
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