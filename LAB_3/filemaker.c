// Making Worst, Best, and Average Case (Without Repeated Elements)Input Files
#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fpworst, *fpbest, *fpaverage;
    fpworst = fopen("worst_case_input.txt", "w");
    fpbest = fopen("best_case_input.txt", "w");
    fpaverage = fopen("average_case_input.txt", "w");
    if (fpworst == NULL || fpbest == NULL || fpaverage == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    int n = 10000;  
    for (int i = 1; i <= n; i++) {
        fprintf(fpbest, "%d\n", i);           
        fprintf(fpworst, "%d\n", n - i + 1);  
        int randomNum = rand(); //random number for average case
        fprintf(fpaverage, "%d\n", randomNum);
    }
    fprintf(fpworst, "\n");
    fprintf(fpbest, "\n");
    fprintf(fpaverage, "\n");

    fclose(fpworst);
    fclose(fpbest);
    fclose(fpaverage);
    printf("Input files generated successfully.\n");
    return 0;
}
