#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int main(int argc, char* argv[]) {
    FILE *fp = fopen(argv[1], "rb");
    char* line = malloc(SIZE);
    size_t n = 0;
    int read = 0;

    while (1) {
        int num = 0;
        char ch;
        if (fread(&num, 4, 1, fp) == 0) {
            break;
        }
        if(fread(&ch, 1, 1, fp) == 0){
            break;
        }
        for (size_t i = 0; i <= num; i++) {
            fputs(&ch, stdout);
        }
    }
    

    return 0;
}