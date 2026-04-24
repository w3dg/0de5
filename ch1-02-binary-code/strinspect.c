/**
 * Author: Debopam Gupta https://github.com/w3dg
 * Inspired by 0DE5 by Kay Lack
 * https://youtu.be/CcJXdyH7AUw
 * https://www.0de5.net/stimuli/binary-code
 *
 * Compile and run with:
 * gcc -g -O0 -o strinspect ./strinspect.c  && ./strinspect "Hello"
 *
 */

#include <stdio.h>
#include <string.h>

#define CHR_ZERO_ASCII_OFFSET 48

int main(int argc, const char **argv)
{
  if (argc != 2)
  {
    fprintf(stderr, "Usage: strinspect <string>\n");
    return 1;
  }

  int len_input = strlen(argv[1]);

  char bytestr[9];
  for (int i = 0; i < len_input; i++)
  {
    char c = argv[1][i];
    char b = c;
    for (int j = 7; j >= 0; j--)
    {
      bytestr[j] = CHR_ZERO_ASCII_OFFSET + (b & 1);
      b = b >> 1;
    }
    bytestr[8] = '\0';

    printf("idx %d: %s\t", i, bytestr);
    printf("%c \t %3d \t 0x%x \n", c, c, c);
  }
}
