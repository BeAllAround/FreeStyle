struct node
{
  int value;
  struct node* left;
  struct node* right;
};

int _sumTheTreeValues(struct node* root, int n)
{
  if(root)
    n+=root->value;
  if(root->left)
    n = _sumTheTreeValues(root->left, n);
  if(root->right)
    n = _sumTheTreeValues(root->right, n);
  return n;
}

int sumTheTreeValues(struct node* root)
{
  return _sumTheTreeValues(root, 0);
}

/*
#include <stddef.h> // NULL

struct node
{
  int value;
  struct node* left;
  struct node* right;
};

int sumTheTreeValues(struct node* root)
{
  return (root == NULL) ? 0 : root->value + sumTheTreeValues(root->left) + sumTheTreeValues(root->right);
}
*/
