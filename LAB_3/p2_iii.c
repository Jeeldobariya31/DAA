//ake file input from file and sort it using Insertion sort and write the output to another file for all case also note time taken for each case 
//for 100 elements
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertionSort(int arr[], int n, const char* outputFile) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    
        FILE* fp = fopen(outputFile, "w");
        if (fp == NULL) {
            printf("Error opening file %s for writing!\n", outputFile);
            return;
        }
        for (int i = 0; i < n; i++) {
            fprintf(fp, "%d ", arr[i]);
        }
        fclose(fp);
    }

int main() {
    FILE *fpworst, *fpbest, *fpaverage;
    fpworst = fopen("worst_case_input.txt", "r");
    fpbest = fopen("best_case_input.txt", "r");
    fpaverage = fopen("average_case_input.txt", "r");
    if (fpworst == NULL || fpbest == NULL || fpaverage == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    int n = 100;  
    int* arrWorst = (int*)malloc(n * sizeof(int));
    int* arrBest = (int*)malloc(n * sizeof(int));
    int* arrAverage = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        fscanf(fpworst, "%d", &arrWorst[i]);
        fscanf(fpbest, "%d", &arrBest[i]);
        fscanf(fpaverage, "%d", &arrAverage[i]);
    }

    clock_t start, end;
    
    start = clock();
    insertionSort(arrWorst, n, "worst_case_output100.txt");
    end = clock();
    double timeWorst = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    insertionSort(arrBest, n, "best_case_output100.txt");
    end = clock();
    double timeBest = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    insertionSort(arrAverage, n, "average_case_output100.txt");
    end = clock();
    double timeAverage = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken for(100) worst case: %f seconds\n", timeWorst);
    printf("Time taken for(100) best case: %f seconds\n", timeBest);
    printf("Time taken for(100) average case: %f seconds\n", timeAverage);

    free(arrWorst);
    free(arrBest);
    free(arrAverage);

    fclose(fpworst);
    fclose(fpbest);
    fclose(fpaverage);


        return 0;
}
