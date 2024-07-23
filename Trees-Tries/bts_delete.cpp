/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* MinRight(TreeNode* root){
        TreeNode* node = root;
        while(node!=NULL && node->left!=NULL)
            node = node->left;
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root;
        if(key<root->val)
            root->left = deleteNode(root->left, key);
        else if(key>root->val)
            root->right = deleteNode(root->right, key);
        else
        {
            //single or no child
            if(root->right==NULL)
            {
                TreeNode* current = root->left;
                delete(root);
                return current;
            }
            else if(root->left==NULL)
            {
                TreeNode* current = root->right;
                delete(root);
                return current;
            }
            //2 children
            else
            {
                TreeNode* current = MinRight(root->right);
                root->val = current->val;
                root->right = deleteNode(root->right, current->val);
            }
        }
        return root;
    }
};