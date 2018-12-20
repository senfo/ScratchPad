#include <stdio.h>

typedef struct Node {
  struct Node *left;
  struct Node *right;
} Node;

int maxDepth(Node);

int main(void)
{
  int depth;
  Node root;
  Node a, b, c;
  
  c.left = NULL;
  c.right = NULL;
  
  b.left = &c;
  b.right = NULL;
  
  a.left = NULL;
  a.right = &b;
  
  root.left = NULL;
  root.right = &a;

  depth = maxDepth(root);
  printf("%d\n", depth);

  return 0;
}

int maxDepth(Node node)
{
  int left = 0;
  int right = 0;

  if (node.left != NULL)
  {
    left++;
    left += maxDepth(*node.left);
  }

  if (node.right != NULL)
  {
    right++;
    right += maxDepth(*node.right);
  }

  return left > right ? left : right;
}
