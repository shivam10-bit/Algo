#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input3.txt output3.txt\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fin = fopen(argv[1], "r");
    if (!fin) { perror("opening input file"); return EXIT_FAILURE; }
    FILE *fout = fopen(argv[2], "w");
    if (!fout) { perror("opening output file"); fclose(fin); return EXIT_FAILURE; }

    int a, b;
    int pairCount = 0;
    while (fscanf(fin, "%d %d", &a, &b) == 2) {
        int g = gcd(a, b);
        fprintf(fout, "The GCD of %d and %d is %d\n", a, b, g);
        pairCount++;
    }

    fclose(fin);
    fclose(fout);

    if (pairCount < 20) {
        fprintf(stderr, "Warning: only %d pairs were read (expected at least 20).\n", pairCount);
    }

    // Display contents of output file
    fout = fopen(argv[2], "r");
    if (!fout) { perror("reopening output file"); return EXIT_FAILURE; }

    char line[256];
    while (fgets(line, sizeof(line), fout)) {
        fputs(line, stdout);
    }

    fclose(fout);
    return EXIT_SUCCESS;
}
