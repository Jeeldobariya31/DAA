// power of a number with recursion     
#include<stdio.h>       
#include<time.h>        
int power(int base, int exp){
    if(exp == 0)
        return 1;
    else
        return base * power(base, exp-1);
}  

int main(){
        int base, exp;
        clock_t start, end;
        start = clock();
        printf("Enter base and exponent: ");
        scanf("%d %d", &base, &exp);
        printf("%d raised to the power %d is %d", base, exp, power(base, exp));
        end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("\nTime taken to calculate power: %f seconds", time_taken);
        return 0;                       
} 