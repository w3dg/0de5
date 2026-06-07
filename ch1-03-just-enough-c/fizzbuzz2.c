#include <stdio.h>
#include <stdlib.h>

#define BUFLEN 1000

/**
 * Author: Debopam Gupta https://github.com/w3dg
 * Inspired by 0DE5 by Kay Lack
 * https://www.0de5.net/stimuli/binary-formats-through-bitmap-images
 */

void build_string(char *, int, int);

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

  char buffer[BUFLEN] = {0};
  build_string(buffer, BUFLEN, limit);

  printf("%s", buffer);
}

void build_string(char *buffer, int buf_size, int limit)
{
  // snprintf starts at buf[0]
  // manually keep track of last written byte offset
  int offset = 0;

  for (int i = 1; i <= limit; i++)
  {
    int r = 0;

    if (i % 15 == 0)
      r = snprintf(buffer + offset, buf_size - offset, "FizzBuzz");
    else if (i % 3 == 0)
      r = snprintf(buffer + offset, buf_size - offset, "Fizz");
    else if (i % 5 == 0)
      r = snprintf(buffer + offset, buf_size - offset, "Buzz");
    else
      r = snprintf(buffer + offset, buf_size - offset, "%d", i);

    if (r < 0 || r >= buf_size - offset)
    {
      fprintf(stderr, "Buffer too small or encoding error\n");
      break;
    }

    offset += r;

    // Add separator if not the last element
    if (i < limit)
    {
      r = snprintf(buffer + offset, buf_size - offset, ", ");
      if (r < 0 || r >= buf_size - offset)
        break;
      offset += r;
    }
    else
    {
      // full stop at the end
      snprintf(buffer + offset, buf_size - offset, ".");
    }
    // buffer is null-terminated here by the last snprintf — no extra step needed
  }
}
