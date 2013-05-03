/* Calculates the sum of all even-valued terms in the Fibonacci sequence */
/* below four million */

#include <stdio.h>
#include <limits.h>

int main(void)
{
  int i,
      first  = 1,
      previous = 1,
      next = 1,
      total  = 0;

  for (i = 0; i < INT_MAX; i++)
  {
    printf("%d, ", next);

    if (first + previous > 4000000)
    {
      break;
    }

    next = first + previous;
    first = previous;
    previous = next;

    if (!(next % 2))
    {
      total += next;
    }
  }

  printf("\n");
  printf("%d\n", total);

  return 0;
}
