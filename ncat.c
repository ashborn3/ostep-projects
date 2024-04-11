#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE *fp;
    int c;
    if (argc == 1) {
        printf("ncat: 0 arguments given\n");
        return -1;
    }
    for(int i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("ncat: Failed to open %s file\n", argv[i]);
            continue;
        }
        printf("-- %s --\n", argv[i]);
        while (1) {
            c = fgetc(fp);
            if (c == EOF) {
                break;
            }
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}
