// print prime fectors of a number with recursion
#include<stdio.h>
#include<time.h>

void primeFactors(int n){
    if(n <= 1)
        return;
    for(int i = 2; i <= n; i++){
        if(n % i == 0){
            printf("%d ", i);
            primeFactors(n/i);
            break;
        }
    }
}

int main(){
    int n;
    clock_t start, end;
    start = clock();
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Prime factors of %d are: ", n);
    primeFactors(n);
    end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to calculate prime factors: %f seconds", time_taken);
    return 0;
}