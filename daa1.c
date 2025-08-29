#include <stdio.h>
#include <limits.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    if (!fin) {
        fprintf(stderr, "Cannot open input file\n");
        return 1;
    }

    int n;
    if (fscanf(fin, "%d", &n) != 1 || n < 2) {
        printf("Not enough elements\n");
        fclose(fin);
        return 0;
    }

    int smallest_6309 = INT_MAX, s_smallest_6309 = INT_MAX;
    int largest_6309 = INT_MIN, s_largest_6309 = INT_MIN;
    int x;

    for (int i = 0; i < n; i++) {
        if (fscanf(fin, "%d", &x) != 1) break;
        if (x < smallest_6309) {
            s_smallest_6309 = smallest_6309;
            smallest_6309 = x;
        } else if (x > smallest_6309 && x < s_smallest_6309) {
            s_smallest_6309 = x;
        }
        if (x > largest_6309) {
            s_largest_6309 = largest_6309;
            largest_6309 = x;
        } else if (x < largest_6309 && x > s_largest_6309) {
            s_largest_6309 = x;
        }
    }
    fclose(fin);

    if (s_smallest_6309 == INT_MAX)
        printf("Second smallest not found \n");
    else
        printf("Second smallest = %d\n", s_smallest_6309);

    if (s_largest_6309 == INT_MIN)
        printf("Second largest not found \n");
    else
        printf("Second largest = %d\n", s_largest_6309);
        return 0;
}
