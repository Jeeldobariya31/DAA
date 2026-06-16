//Given an array arr[], the task is to generate all the possible adjacent subarrays of the given array. 
// Examples:  
 
// Input: arr[] = [1, 2, 3] 
// Output: [ [1], [1, 2], [2], [1, 2, 3], [2, 3], [3] ] 

#include <stdio.h>
#include <stdlib.h>

void generateSubarrays(int arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            printf("[");
            for (int k = i; k <= j; k++) {
                printf("%d", arr[k]);
                if (k < j) {
                    printf(", ");
                }
            }
            printf("] ");
        }
    }
    printf("]\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Adjacent subarrays: ");
    generateSubarrays(arr, n);

    free(arr);
    return 0;
}
