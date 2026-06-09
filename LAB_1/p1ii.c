//factorial without recursion
#include<stdio.h>
#include<time.h>

int main(){
    int n, i, fact = 1;
    clock_t start, end;
    printf("Enter a number: ");
    scanf("%d", &n);
    start = clock();    
    for(i = 1; i <= n; i++){
        fact = fact * i;
    }
    printf("Factorial of %d is %d", n, fact);
        end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("\nTime taken to calculate factorial: %f seconds", time_taken);
    return 0;
}