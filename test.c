// test.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress.h"

int main() {
    char choice[10];
    char file[100];

    // Compression
    strcpy(choice, "-c");
    strcpy(file, "input.txt");
    FILE* fp = fopen(file, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    fprintf(fp, "123456789");
    fclose(fp);
    printf("Performing compression with text file input...\n");
    system("./compress -c input.txt");

    // Decompression
    strcpy(choice, "-d");
    strcpy(file, "input.bin");
    fp = fopen(file, "wb");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    char content[] = "111110000111100100010110111100010011101100101";
    fwrite(content, sizeof(char), strlen(content), fp);
    fclose(fp);
    printf("\nPerforming decompression with binary file input...\n");
    system("./compress -d input.bin");

    return 0;
}
