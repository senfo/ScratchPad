/* Finds the largest palindrome made from the product of two 3-digit numbers. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define ARRAY_SIZE 8
#define START 999
#define FINISH 99

#define max(a, b) (((a) > (b)) ? (a) : (b))

void reverse(char *);

int main(void)
{
  int x, y, largest = 0;
  char buffer[ARRAY_SIZE];
  char *reversed;
  size_t length;

  for (x = START; x > FINISH; x--)
  for (y = START; y > FINISH; y--)
  {
    sprintf(buffer, "%d", x * y);
    length = strlen(buffer);
    reversed = malloc((length + 1) * sizeof(char));
    strncpy(reversed, buffer, length);
    reverse(reversed);

    if (strcmp(buffer, reversed) == 0)
    {
      largest = max(largest, x * y);
    }

    strncpy(reversed, "\0", length);
    free(reversed);
  }

  printf("%d\n", largest);

  return 0;
}


void reverse(char *s)
{
  int length = strlen(s);
  int c, i, j;

  for (i = 0, j = length - 1; i < j; i++, j--)
  {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
