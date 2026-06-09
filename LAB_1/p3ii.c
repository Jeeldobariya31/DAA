// find number of digits in a number without recursion
#include<stdio.h>
#include<time.h>

int countDigits(int n){
    int count = 0;
    while(n != 0){
        n = n / 10;
        count++;
    }
    return count;
}

int main(){
    int n;
    clock_t start, end;
    start = clock();
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Number of digits in %d is %d", n, countDigits(n));
    end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to calculate number of digits: %f seconds", time_taken);
    return 0;
}
