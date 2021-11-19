#include <stdbool.h>

struct node {
  int value;
  struct node *left, *right;
};

bool search (int n, const struct node *root)
{
  if(!root)
    return false;
  if(root->value == n)
    return true;
  if(root->left)
    if(search(n, root->left))
      return true;
  if(root->right)
    if(search(n, root->right))
      return true;
  return false;
}
