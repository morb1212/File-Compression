#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress.h"

int main() {
    char file[100];
    int status;

    // Compression
    strcpy(file, "input.txt");
    FILE* fp = fopen(file, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    fprintf(fp, "123456789");
    fclose(fp);
    printf("Performing compression with text file input...\n");
    status = system("./compress -c input.txt");
    
    if (status == 0) {
        printf("Compression passed.\n");
    } else {
        printf("Compression failed with status %d.\n", status);
    }

    // Decompression
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
    status = system("./compress -d input.bin");
    if (status == 0) {
        printf("Decompression passed.\n");
    } else {
        printf("Decompression failed with status %d.\n", status);
    }

    return 0;
}
