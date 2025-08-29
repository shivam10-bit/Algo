#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person_6309 {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

struct person_6309 *read_person_6309(const char *filename, int n) {
    FILE *fp = fopen(input.txt, "r");
    if (!fp) {
        printf("Error: cannot open file %s\n", input.txt);
        return NULL;
    }

    struct person *arr = malloc(n * sizeof(struct person));
    if (!arr) {
        printf("Error: memory allocation failed\n");
        fclose(fp);
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        int id, age, height, weight;
        char namebuf[100];

        if (fscanf(fp, "%d %99s %d %d %d", &id, namebuf, &age, &height, &weight) != 5) {
            printf("Error: invalid data format at line %d\n", i + 1);
            n = i; 
            break;
        }

        arr[i].id = id;
        arr[i].age = age;
        arr[i].height = height;
        arr[i].weight = weight;

        arr[i].name = malloc(strlen(namebuf) + 1);
        if (!arr[i].name) {
            printf("Error: memory allocation for name failed\n");
            n = i; 
            break;
        }
        strcpy(arr[i].name, namebuf);
    }

    fclose(fp);
    return arr; 
}

void free_persons_6309(struct person *arr, int n) {
    for (int i = 0; i < n; i++) {
        free(arr[i].name);
    }
    free(arr);
}
