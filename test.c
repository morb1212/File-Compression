// test.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress.h"

int main() {
    char choice[10];
    char file[100];

    // Compression with text file input
    strcpy(choice, "-c");
    strcpy(file, "input.txt");
    FILE* fp = fopen(file, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    fprintf(fp, "123456789");
    fclose(fp);
    system("echo 'Before compression:' && cat input.txt");
    system("./compress -c input.txt");
    system("echo 'After compression:' && cat input.bin");
    system("./compress -d input.bin");
    system("echo 'After decompression:' && cat input.txt");
    printf("\n");

    // Compression with binary file input
    strcpy(choice, "-c");
    strcpy(file, "input.bin");
    fp = fopen(file, "wb");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    char content[] = "123456789";
    fwrite(content, sizeof(char), strlen(content), fp);
    fclose(fp);
    system("echo 'Before compression:' && hexdump -C input.bin");
    system("./compress -c input.bin");
    system("echo 'After compression:' && hexdump -C input.bin");
    system("./compress -d input.bin");
    system("echo 'After decompression:' && hexdump -C input.bin");

    return 0;
}
