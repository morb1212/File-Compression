// test.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress.h"

int main() {
    char choice[10];
    char file[100];

    printf("Enter choice: ");
    scanf("%s", choice);
    printf("Enter file name: ");
    scanf("%s", file);

    char* type = strrchr(file, '.');
    if (type != NULL) {
        type++; 
        FILE* fp = fopen(file, "r");
        if (fp == NULL) {
            printf("Error opening file.\n");
            return 1;
        }

        char content[1000];
        int num_read = fread(content, sizeof(char), sizeof(content), fp);
        fclose(fp);
        content[num_read] = '\0'; 

        char result[1000] = {0}; 

        if (strcmp(choice, "-c") == 0 && strcmp(type, "txt") == 0) {
            reverseString(content);
            // Compression operation
            int num = atoi(content);
            int numdig = numDig(num);
            int even=numdig;
            if (content[0] == '0') {
                strcat(result, "1111");
                even++;
            }
            for (int i = numdig - 1; i >= 0; i--) {
                char* now = code_NumToBin(getDigit(num, i));
                strcat(result, now);
            }

            if (even % 2 != 0) {
                strcat(result, "0000");
            }

            char outputFileName[100];
            strncpy(outputFileName, file, strlen(file) - strlen(type)); 
            outputFileName[strlen(file) - strlen(type)] = '\0'; 
            strcat(outputFileName, "bin");
            writeToFile(outputFileName, result);
        } else if (strcmp(choice, "-d") == 0 && strcmp(type, "bin") == 0) {
             int numdig = strlen(content) / 4;
            int dig = strlen(content);
            for (int i = numdig - 1; i >= 0; i--) {
                char* now = code_BinToNum(content + i * 4);  
                strcat(result, now);
                memmove(content + i * 4, content + (i + 1) * 4, dig - (i + 1) * 4 + 1);
            }
            reverseString(result);
            char outputFileName[100];
            strncpy(outputFileName, file, strlen(file) - strlen(type)); 
            outputFileName[strlen(file) - strlen(type)] = '\0'; 
            strcat(outputFileName, "txt");
            writeToFile(outputFileName, result);
        } else {
            printf("Invalid choice or file type.\n");
            return 1;
        }
    }

    return 0;
}
