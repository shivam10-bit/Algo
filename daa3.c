#include <stdio.h>
#include <stdlib.h>

void findDuplicate_6309(int *arr, int n) {
    int duplicateCount_6309 = 0;
    int mostFreq = arr[0];
    int maxCount_6309 = 1;

    for (int i = 0; i < n; i++) {
        // Check if arr[i] has already been checked
        int seen = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] == arr[i]) {
                seen = 1;
                break;
            }
        }
        if (seen) {
            printf("Element %d already checked for duplicates.\n", arr[i]);
            continue;
        }

        int count = 1; 
        printf("Checking element %d for duplicates: ", arr[i]);
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == arr[i]) {
                printf("%d ", arr[j]);
                count++;
            }
        }
        if (count > 1) {
            printf("-> Found %d duplicates of %d\n", count - 1, arr[i]);
            duplicateCount_6309++;
        } else {
            printf("-> No duplicates found\n");
        }
        if (count > maxCount_6309) {
            maxCount_6309 = count;
            mostFreq = arr[i];
        }
    }

    printf("Total number of duplicate values = %d\n", duplicateCount_6309);
    printf("The most repeating element in the array = %d\n", mostFreq);
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    if (!fin) {
        fprintf(stderr, "Cannot open input file\n");
        return 1;
    }

    int n;
    fscanf(fin, "%d", &n);
    if (n <= 0) {
        printf("Invalid size\n");
        fclose(fin);
        return 0;
    }

    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        perror("Memory allocation failed");
        fclose(fin);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &arr[i]);
    }
    fclose(fin);

    findDuplicate_6309(arr, n);

    free(arr);
    return 0;
}
