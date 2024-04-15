#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000

int main(int argc, char* argv[]) {
    FILE *fp = NULL;
    char *str = NULL;
    char *line = malloc(SIZE);
    size_t n = SIZE;
    for(int i = 2; i < argc; i++) {
        fp = fopen(argv[i], "r");
        printf("%s\n", argv[i]);
        if (fp == NULL) {
            printf("Error: File not found\n");
            return 1;
        }
        while (getline(&line, &n, fp) > 0) {
            str = strstr(line, argv[1]);
            if (str != NULL) printf("%s\n", line);
        }
        fclose(fp);
    }
    free(line);
    return 0;
}
