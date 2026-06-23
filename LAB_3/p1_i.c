//ake file input from file and sort it using bubble sort and write the output to another file for all case also note time taken for each case 
//for 10000 elements
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubbleSort(int arr[], int n , const char* outputFile) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    
    int n = 10000;  
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
    bubbleSort(arrWorst, n, "worst_case_output.txt");
    end = clock();
    double timeWorst = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    bubbleSort(arrBest, n, "best_case_output.txt");
    end = clock();
    double timeBest = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    bubbleSort(arrAverage, n, "average_case_output.txt");
    end = clock();
    double timeAverage = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken for(10000) worst case: %f seconds\n", timeWorst);
    printf("Time taken for(10000) best case: %f seconds\n", timeBest);
    printf("Time taken for(10000) average case: %f seconds\n", timeAverage);

    free(arrWorst);
    free(arrBest);
    free(arrAverage);

    fclose(fpworst);
    fclose(fpbest);
    fclose(fpaverage);


        return 0;
}
