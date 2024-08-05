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
    void dfs(TreeNode* root, int i, vector<int>& res)
    {
        if(!root) return;
        if(res.size()==i)
            res.push_back(root->val);

        // LV
        if(root->right) dfs(root->right, i+1, res);
        if(root->left) dfs(root->left, i+1, res);

        // RV
        if(root->left) dfs(root->left, i+1, res);
        if(root->right) dfs(root->right, i+1, res);        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};
