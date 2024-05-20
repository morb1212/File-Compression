#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char choice[10];
    char file[100];
    int status;

    // Set the choice directly here
    strcpy(choice, "-c");

    // Define the file name
    strcpy(file, "inputC.txt");
    FILE* fp = fopen(file, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    fprintf(fp, "123456789");
    fclose(fp);
    printf("Performing compression with text file input...\n");
    status = system("./compress -c inputC.txt"); 
    if (status != 0) {
        printf("Error creating compressed file.\n");
        return 1;
    }

    // Check if the compressed file exists
    FILE* compressedFile = fopen("inputC.bin", "rb");
    if (compressedFile == NULL) {
        printf("Error opening compressed file.\n");
        return 1;
    }

    // Read the contents of the compressed file
    fseek(compressedFile, 0, SEEK_END);
    long compressedFileSize = ftell(compressedFile);
    rewind(compressedFile);
    char* compressedContent = (char*)malloc(compressedFileSize + 1);
    fread(compressedContent, sizeof(char), compressedFileSize, compressedFile);
    compressedContent[compressedFileSize] = '\0';
    fclose(compressedFile);

    // Verify the contents of the compressed file
    printf("Contents of compressed file: %s\n", compressedContent);

    // Verify if the compressed content matches the expected output
    if (strcmp(compressedContent, "1110110111001011101010011000011101100000") == 0) {
        printf("Compression passed.\n");
    } else {
        printf("Compression failed.\n");
        return 1;
    }

    // Free the allocated memory for compressedContent
    free(compressedContent);

    // Decompression
    strcpy(choice, "-d");
    strcpy(file, "inputD.bin");
    fp = fopen(file, "wb");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    char content[] = "1110110111001011101010011000011101100000";
    fwrite(content, sizeof(char), strlen(content), fp);
    fclose(fp);
    printf("\nPerforming decompression with binary file input...\n");
    status = system("./compress -d inputD.bin"); 
    if (status != 0) {
        printf("Error during decompression.\n");
        return 1;
    }

    // Check if the decompressed file exists
    FILE* decompressedFile = fopen("inputD.txt", "rb");
    if (decompressedFile == NULL) {
        printf("Error opening decompressed file.\n");
        return 1;
    }

    // Read the contents of the decompressed file
    fseek(decompressedFile, 0, SEEK_END);
    long decompressedFileSize = ftell(decompressedFile);
    rewind(decompressedFile);
    char* decompressedContent = (char*)malloc(decompressedFileSize + 1);
    fread(decompressedContent, sizeof(char), decompressedFileSize, decompressedFile);
    decompressedContent[decompressedFileSize] = '\0';
    fclose(decompressedFile);

    // Verify the contents of the decompressed file
    printf("Contents of decompressed file: %s\n", decompressedContent);

    // Verify if the decompressed content matches the original input
    if (strcmp(decompressedContent, "123456789") == 0) {
        printf("Decompression passed.\n");
    } else {
        printf("Decompression failed.\n");
        return 1;
    }

    // Free the allocated memory for decompressedContent
    free(decompressedContent);

    return 0;
}
