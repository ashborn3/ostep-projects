#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printf("No Argument Given\nreverse <INPUT> <OUTPUT>\n");
        exit(1);
    }
    else if (argc == 3) {
        if (argv[1] == argv[2]) {
            printf("Input and Output Files can't be the same\n");
            exit(1);
        }
    }
    else if (argc > 3) {
        printf("reverse <INPUT> <OUTPUT>\n");
        exit(1);
    }
    


    char* line;
    char* lineArr[SIZE];
    size_t n;
    int indexOfLineArr = 0;
    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Input file failed to open\n");
        exit(1);
    }

    while (getline(&line, &n, fp) != -1) {
        char* allocatedLine = (char *) malloc(SIZE);
        strncpy(allocatedLine, line, SIZE);
        lineArr[indexOfLineArr++] = allocatedLine;
    }

    if (argc == 2) {
        for (int i = indexOfLineArr - 1; i >= 0; i--) {
            printf("%s", lineArr[i]);
            free(lineArr[i]);
        }
    }
    else if (argc == 3) {
        FILE *fp2 = fopen(argv[2], "w");

        if (fp2 == NULL) {
            printf("Output file failed to open\n");
            exit(1);
        }

        for (int i = indexOfLineArr - 1; i >= 0; i--) {
            fprintf(fp2, "%s", lineArr[i]);
            free(lineArr[i]);
        }
        fclose(fp2);
    }
    fclose(fp);
    return 0;
}