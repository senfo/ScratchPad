#include <stdio.h>

typedef struct Node {
  struct Node *left;
  struct Node *right;
} Node;

int depth(struct Node *n);

int main(void)
{
  struct Node n = {{NULL, NULL}, NULL};
  int d = depth(&n);

  printf("%d\n", d);

  return 0;
}

int depth(struct Node *n)
{
  int x = 1;

  if (n->left != NULL)
  {
    x += depth(n->left);
  }

  if (n->right != NULL)
  {
    x += depth(n->right);
  }

  return x;
}
