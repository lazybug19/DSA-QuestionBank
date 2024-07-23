#include <bits/stdc++.h>
using namespace std;

class tree
{
    public:
        int data;
        tree* left;
        tree* right;
        
    tree(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

int main()
{
    
    tree* root= new tree(1);
    root->left= new tree(2);
    root->right= new tree(3);
    root->left->left= new tree(4);
    root->left->right= new tree(5);
    root->right->left= new tree(6);
    root->right->right= new tree(7);

    return 0;
}