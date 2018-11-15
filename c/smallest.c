/* Finds the smallest number that is evenly divisible by all of the numbers from 1 to 20 */
#include <stdio.h>
#include <limits.h>

int main(void)
{
  unsigned int x;

  for (x = 20; x < UINT_MAX; x++)
  {
    if (x % 1 == 0 &&
        x % 2 == 0 &&
        x % 3 == 0 &&
        x % 4 == 0 &&
        x % 5 == 0 &&
        x % 6 == 0 &&
        x % 7 == 0 &&
        x % 8 == 0 &&
        x % 9 == 0 &&
        x % 10 == 0 &&
        x % 11 == 0 &&
        x % 12 == 0 &&
        x % 13 == 0 &&
        x % 14 == 0 &&
        x % 15 == 0 &&
        x % 16 == 0 &&
        x % 17 == 0 &&
        x % 18 == 0 &&
        x % 19 == 0 &&
        x % 20 == 0)
    {
      break;
    }
  }

  printf("%d\n", x);
  return 0;
}
