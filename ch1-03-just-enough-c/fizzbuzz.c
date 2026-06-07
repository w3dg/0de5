#include <stdio.h>
#include <stdlib.h>

/**
 * Author: Debopam Gupta https://github.com/w3dg
 * Inspired by 0DE5 by Kay Lack
 * https://www.0de5.net/stimuli/binary-formats-through-bitmap-images
 */

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s [n]", argv[0]);
    fprintf(stderr, "n: limit upto which to print fizzbuzz numbers");
    return 1;
  }

  int limit = atoi(argv[1]);
  if (limit == 0)
  {
    fprintf(stderr, "Error converting given limit (n). Limit can be any number above 0");
    return 1;
  }

  for (int i = 1; i <= limit; i++)
  {
    if (i % 3 == 0 && i % 5 == 0)
    {
      printf("FizzBuzz");
    }
    else if (i % 3 == 0)
    {
      printf("Fizz");
    }
    else if (i % 5 == 0)
    {
      printf("Buzz");
    }
    else
    {
      printf("%d", i);
    }
    printf("\n");
  }
}
