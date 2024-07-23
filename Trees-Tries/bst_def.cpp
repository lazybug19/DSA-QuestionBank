#include <bits/stdc++.h>
using namespace std;

class bst{
    public:
      int data;
      bst* left;
      bst* right;
      
      bst(int val)
      {
        data = val;
        left = right = NULL;
      }
};

bst* insert(int val, bst* node)
{
    if(node == NULL)
        node=new bst(val);
    if(val < node->data)
        node->left=insert(val, node->left);
    else if(val > node->data)
        node->right=insert(val, node->right);
    return node;
}
int main()
{
    bst* root = NULL;
    root = insert(4, root);
    insert(5, root);
    insert(6, root);
    insert(7, root);
    insert(1, root);
    insert(2, root);
    insert(3, root);
    return 0;
}
