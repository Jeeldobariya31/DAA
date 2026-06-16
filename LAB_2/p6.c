// Given a positive integer n, find whether it can be represented as the sum of two or more consecutive positive integers and also print that consecutive sequence.

#include <stdio.h>

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    int found = 0; 
    for (int start = 1; start < n; start++) {
        int sum = 0;
        for (int end = start; end < n; end++) {
            sum += end;
            if (sum == n) {
                found = 1;
                printf("%d can be represented as the sum of consecutive integers: ", n);
                for (int i = start; i <= end; i++) {
                    printf("%d ", i);
                }
                printf("\n");
                break;
            } else if (sum > n) {
                break;
            }
        }
        if (found) {
            break;
        }
    }
    if (!found) {
        printf("%d cannot be represented as the sum of two or more consecutive integers.\n", n);
    }
    return 0;

}

// n&(n-1)!=0 is a common bitwise operation used to check if a number is a power of two. If n is a power of two, it has only one bit set in its binary representation. When you subtract 1 from a power of two, all the bits after the single set bit become 1, and the single set bit becomes 0. Therefore, performing a bitwise AND between n and (n-1) will yield 0 if n is a power of two.