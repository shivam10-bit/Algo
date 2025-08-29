#include <stdio.h>
#include <stdlib.h>


// Function to calculate and print prefix sum steps
void fprefixSum_6309(int arr[], int prefix_6309[], int n) {
    prefix_6309[0] = arr[0];
    printf("prefix_6309[0] = arr[0] = %d\n", arr[0]);
    for (int i = 1; i < n; i++) {
        printf("prefix_6309[%d] = prefix_6309[%d] + arr[%d] = %d + %d = ", i, i-1, i, prefix_6309[i-1], arr[i]);
        prefix_6309[i] = prefix_6309[i-1] + arr[i];
        printf("%d\n", prefix_6309[i]);
    }
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    if (!fin) {
        printf("Cannot open input file\n");
        return 1;
    }

    int n;
    fscanf(fin, "%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    int *prefix_6309 = (int*)malloc(n * sizeof(int));
    if (!arr || !prefix_6309) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &arr[i]);
    }
    fclose(fin);

    printf("Prefix sum calculation steps:\n");
    fprefixSum_6309(arr, prefix_6309, n);

    printf("Prefix sum array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", prefix_6309[i]);
    }
    printf("\n");
    free(arr);
    free(prefix_6309);
    return 0;
}


