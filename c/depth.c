#include <stdio.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

typedef struct Node {
  struct Node *left;
  struct Node *right;
} Node;

typedef struct NodeDepth {
  int left;
  int right;
} NodeDepth;

int maxDepth(Node *);
NodeDepth discreteDepth(Node);

int main(void)
{
  int depth;
  Node root;
  Node a, b, c, d;
  NodeDepth nodeDepth;
  
  d.left = NULL;
  d.right = NULL;
  
  c.left = NULL;
  c.right = NULL;
  
  b.left = &c;
  b.right = &d;
  
  a.left = NULL;
  a.right = &b;
  
  root.left = NULL;
  root.right = &a;

  depth = maxDepth(&root);
  nodeDepth = discreteDepth(root);
  
  printf("Maximum Depth: %d  -  Left Depth: %d  -  Right Depth: %d\n", depth, nodeDepth.left, nodeDepth.right);

  return 0;
}

int maxDepth(Node *node)
{
  if (node == NULL)
  {
    return 0;
  }
  
  return 1 + MAX(maxDepth(node->left), maxDepth(node->right));
}

NodeDepth discreteDepth(Node node)
{
  NodeDepth aggregate;
  NodeDepth temp;
  
  aggregate.left = 0;
  aggregate.right = 0;

  if (node.left != NULL)
  {
    temp = discreteDepth(*node.left);

    aggregate.left++;
    aggregate.left += temp.left;
    aggregate.right += temp.right;
  }
  
  if (node.right != NULL)
  {
    temp = discreteDepth(*node.right);

    aggregate.right++;
    aggregate.right += temp.right;
    aggregate.left += temp.left;
  }

  return aggregate;
}
