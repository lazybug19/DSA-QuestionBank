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
    TreeNode* rootNode(TreeNode* root, int val) {
        if(root == NULL)
            return root;
        if(val < root->val)
            root = root->left;
        else if(val > root->val)
            root = root->right;
        else
            return root;
        return rootNode(root, val);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;
        TreeNode* node = rootNode(root, val);
        return node;
    }
};