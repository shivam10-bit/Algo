#include <stdio.h>

void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

// Function to rotate and show each step in the output file
void SHOW_ROTATE_RIGHT(int A[], int N, int k, FILE *fout) {
    fprintf(fout, "Before ROTATE: ");
    for (int i = 0; i < N; i++) {
        fprintf(fout, "%d ", A[i]);
    }
    fprintf(fout, "\n");

    if (k <= 1) {
        fprintf(fout, "No rotation needed (k <= 1)\n");
        return;
    }

    // Show each exchange step
    for (int i = k - 1; i > 0; i--) {
        fprintf(fout, "Exchange A[%d]=%d with A[%d]=%d\n", i, A[i], i-1, A[i-1]);
        EXCHANGE(&A[i], &A[i - 1]);
        fprintf(fout, "Current state: ");
        for (int j = 0; j < N; j++) {
            fprintf(fout, "%d ", A[j]);
        }
        fprintf(fout, "\n");
    }

    fprintf(fout, "After ROTATE:  ");
    for (int i = 0; i < N; i++) {
        fprintf(fout, "%d ", A[i]);
    }
    fprintf(fout, "\n");
}

int main(void) {
    int A[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    int N = sizeof(A) / sizeof(A[0]);
    int k = 5;

    // Open output file
    FILE *fout = fopen("output.txt", "w");
    if (!fout) {
        perror("Cannot open output file");
        return 1;
    }

    SHOW_ROTATE_RIGHT(A, N, k, fout);

    fclose(fout);
    printf("Rotation complete. Results written to output.txt\n");
    return 0;
}
