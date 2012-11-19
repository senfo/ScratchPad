#include <stdio.h>

int main(void)
{
  int i;

  for (i = 1; i <= 100; i++)
  {
    printf("%d - %s%s\n", i, (i % 3 ? "" : "fizz "), (i % 5 ? "" : "buzz"));
  }

  return 0;
}
