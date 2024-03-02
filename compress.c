#include <stdlib.h>
#include "compress.h"
#include <stdio.h>
#include <string.h>

char* code_NumToBin(int comp) {
    char* num;
    switch (comp)
    {
    case 0:  //0000
        num= "1111";
        break;
    case 1:  ///0001
        num= "1110";
        break;
    case 2:   //0010
        num= "1101";
        break;
    case 3:   //0011
        num= "1100";
        break;
    case 4:  //0100
        num= "1011";
        break;
    case 5: //0101
        num= "1010";
        break;   
    case 6:  //0110
        num= "1001";
        break;
    case 7:  //0111
        num= "1000";
        break;
    case 8:   //1000
        num= "0111";
        break;
    case 9: //1001
        num= "0110";
        break;  
    default:
    num="";
        break;
    }
    return num;
}

char* code_BinToNum(char* comp) {
    char* num="";
 if (strcmp(comp, "1111") == 0) {
        num = "0";
    } else if (strcmp(comp, "1110") == 0) {
        num = "1";
    } else if (strcmp(comp, "1101") == 0) {
        num = "2";
    } else if (strcmp(comp, "1100") == 0) {
        num = "3";
    } else if (strcmp(comp, "1011") == 0) {
        num = "4";
    } else if (strcmp(comp, "1010") == 0) {
        num = "5";
    } else if (strcmp(comp, "1001") == 0) {
        num = "6";
    } else if (strcmp(comp, "1000") == 0) {
        num = "7";
    } else if (strcmp(comp, "0111") == 0) {
        num = "8";
    } else if (strcmp(comp, "0110") == 0) {
        num = "9";
    }
    return num;
}

int numDig(int num) {
    int digits=0;
    while (num > 0) {
        digits++;
        num = num / 10;
    }
    return digits;
}

int getDigit(int num, int i) {
    int length = numDig(num);
    for (int j = length - 1; j >= 0; j--) {
        if (j == i)
            return num % 10;
        num /= 10;
    }
    return -1; 
    }

void reverseString(char* str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}