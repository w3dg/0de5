#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>

/**
 * Author: Debopam Gupta https://github.com/w3dg
 * Inspired by 0DE5 by Kay Lack
 * https://www.0de5.net/stimuli/binary-formats-through-bitmap-images
 */

int main(int argc, const char **argv)
{
  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s [n]", argv[0]);
    fprintf(stderr, "n: the limit to count primes between 2 and n");
    return 1;
  }

  int limit = atoi(argv[1]);
  if (limit == 0)
  {
    fprintf(stderr, "Error converting given limit (n). Limit can be any number above 0");
    return 1;
  }

  printf("Prime numbers between 2 and %d\n", limit);

  int c = 0;
  limit--;
  int *nums = malloc(sizeof(int) * limit);

  for (int i = 0; i < limit; i++)
  {
    nums[i] = i + 2;
  }

  int curr = 2;
  int curridx = 0;
  while (curridx < limit)
  {
    while (curridx < limit && curr == -1 && curr != 0)
    {
      curridx++;
      curr = nums[curridx];
    }

    if (curridx == limit)
    {
      break;
    }

    // remove for the current prime to the right
    for (int i = curridx + 1; i < limit; i++)
    {
      if (nums[i] % curr == 0)
      {
        nums[i] = -1;
      }
    }

    curridx++;
    curr = nums[curridx];
  }

  for (int i = 0; i < limit; i++)
  {
    if (nums[i] != -1)
      c++;
    // printf("%d ", nums[i]);
  }
  free(nums);
  printf("There are %d prime numbers between 2 and %d\n", c, limit + 1);
}
