//Given an array arr[] of size n, the task is to rearrange it in alternate positive and negative manner without changing the relative order of 
//positive and negative numbers. In case of extra positive/negative numbers, they appear at the end of the array.

#include<stdio.h>
#include<stdlib.h>

void rearrange(int arr[], int n) {
    int* pos = (int*)malloc(n * sizeof(int));
    int* neg = (int*)malloc(n * sizeof(int));
    int posCount = 0, negCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            pos[posCount++] = arr[i];
        } else {
            neg[negCount++] = arr[i];
        }
    }

    int i = 0, j = 0, k = 0;
    while (i < posCount && j < negCount) {
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }

    while (i < posCount) {
        arr[k++] = pos[i++];
    }

    while (j < negCount) {
        arr[k++] = neg[j++];
    }

    free(pos);
    free(neg);
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

    rearrange(arr, n);

    printf("Rearranged array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}