#include <stdio.h>
#include <stdlib.h>

void decToBin_309(int num, FILE *out) {
    if (num > 1)
        decToBin_309(num / 2, out);
    fprintf(out, "%d", num % 2);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <input2.txt> <output.txt>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    FILE *in = fopen(argv[2], "r");
    FILE *out = fopen(argv[3], "w");

    if (!in || !out) {
        printf("File error.\n");
        return 1;
    }

    int num, count = 0;
    while (fscanf(in, "%d", &num) == 1 && count < n) {
        fprintf(out, "The binary equivalent of %d is ", num);

        int bits = 0, temp = num;
        while (temp > 0) {
            temp /= 2;
            bits++;
        }
        for (int i = 0; i < 16 - bits; i++)
            fprintf(out, "0");

        decToBin_309(num, out);
        fprintf(out, "\n");
        count++;
    }

    fclose(in);
    fclose(out);
    return 0;
}