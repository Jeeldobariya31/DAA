//sum of 1 to n without recursion  
#include<stdio.h>                     
#include<time.h>
int main(){
    int n, i, sum = 0;
    clock_t start, end;
    printf("Enter a number: ");
    scanf("%d", &n);
    start = clock();
    for(i = 1; i <= n; i++){
        sum = sum + i;
    }
    printf("Sum of 1 to %d is %d", n, sum);
    end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to calculate sum: %f seconds", time_taken);
    return 0;
}                                          