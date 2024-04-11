#include <stdio.h>

#define SIZE 1000

int main(int argc, char* argv[]) {
    FILE* fp;
    char* buffer[SIZE];
    for (int i = 2; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("ngrep: failed to open file %s\n", argv[i]);
        }
