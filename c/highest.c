/* Calculate the highest order bit */

#include <stdio.h>
#include <stdlib.h>

void showHelp(char *app);
int highest(int num);

int main(int argc, char **argv)
{
  int num, result;

  if (argc != 2)
  {
    showHelp(argv[0]);
  }
  else
  {
    num = atoi(argv[1]);
    result = highest(num);

    printf("%d\n", result);
  }

  return 0;
}

void showHelp(char *app)
{
  printf("%s <number>\n", app);
}

int highest(int num)
{
  int result = 1;

  if (!num)
  {
    return 0;
  }

  while (num >>= 1)
  {
    result <<= 1;
  }

  return result;
}
