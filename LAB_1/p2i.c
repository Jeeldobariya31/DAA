//sum of 1 to n recursion
#include<stdio.h>
#include<time.h>

int sum(int n){
    if(n == 0)
        return 0;
    else
        return n + sum(n-1);
}

int main(){
    int n;
    clock_t start, end;
    start = clock();
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Sum of 1 to %d is %d", n, sum(n));
    end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to calculate sum: %f seconds", time_taken);
    return 0;
}