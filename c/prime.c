#include <stdio.h>
#include <limits.h>

#define NUMBER 600851475143 

int isPrime(long unsigned int);

int main(void)
{
  long unsigned int i,
                    largest = 0;

  for (i = 3; i < NUMBER; i++)
  {
    if (isPrime(i) && !(NUMBER % i))
    {
      largest = i;
    }
  }

  printf("%lu\n", largest);
  return 0;
}

int isPrime(long unsigned int num)
{
  long unsigned int x;

  for (x = 2; x < num; x++)
  {
    if (num % x == 0 && x != num)
    {
      return 0;
    }
  }

  return 1;
}
