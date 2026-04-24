/**
 * Author: Debopam Gupta https://github.com/w3dg
 * Inspired by 0DE5 by Kay Lack
 * https://youtu.be/CcJXdyH7AUw
 * https://www.0de5.net/stimuli/binary-code
 *
 * Compile and run with
 * gcc -g -O0 -o maker ./maker.c && ./maker
 *
 */

#include <stdio.h>

#define CHR_ZERO_ASCII_OFFSET 48
#define LEN 14

int main()
{
    char bytes[LEN];

    bytes[0x0] = 0b01001101;
    bytes[0x1] = 79;
    bytes[0x2] = 0b00100000;
    bytes[0x3] = 0b01101110;
    bytes[0x4] = 61;
    bytes[0x5] = 0x6D;
    bytes[0x6] = 0b01100101;
    bytes[0x7] = 20;
    bytes[0x8] = 69;
    bytes[0x9] = 73;
    bytes[0xA] = 0b00101110;
    bytes[0xB] = '.';
    bytes[0xC] = 0b00101110;
    bytes[0xD] = 0b00100000;

    printf("Binary  \tHex \tDecimal\tASCII\n");
    printf("--------\t----\t-------\t-----\n");
    char bytestr[9];

    for (int i = 0; i < LEN; i++)
    {
        char b = bytes[i];
        for (int j = 7; j >= 0; j--)
        {
            bytestr[j] = CHR_ZERO_ASCII_OFFSET + (b & 1);
            b = b >> 1;
        }
        bytestr[8] = '\0';
        printf("%s\t", bytestr);
        printf("0x%X\t%d\t%c\n", bytes[i], bytes[i], bytes[i]);
    }

    for (int i = 0; i < LEN; i++)
    {
        printf("%c", bytes[i]);
    }
    printf("\n");

    return 0;
}
