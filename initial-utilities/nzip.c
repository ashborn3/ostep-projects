#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int main(int argc, char* argv[]) {
    FILE *fp = fopen(argv[1], "r");
    char buffer[SIZE], c;
    char *line = malloc(SIZE);
    size_t n = SIZE;
    while (getline(&line, &n, fp) != -1) {
        int i = 0, j = 0;
        while (line[i] != '\0') {
            j = 0;
            while (line[i] == line[i + 1]) {
                i++;
                j++;
            }
            i++;
            //printf("%b%d", j + 1, line[i - 1]);
            fwrite(&j, 4, 1, stdout);
            fputc(line[i - 1], stdout);
        }
    }
    return 0;
}