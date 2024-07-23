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
    pair<int, int> dfs(TreeNode* root)
    {
        if(root==NULL) return {0, 0};
        pair<int, int> left=dfs(root->left);
        pair<int, int> right=dfs(root->right);
        // pair: {taken, notTaken}
        // take current value and left and right notTaken
        int taken = root->val + left.second + right.second;
        // greedy choice 
        int notTaken = max(left.first, left.second) + max(right.first, right.second);
        return {taken, notTaken};
    }
    int rob(TreeNode* root) {
        if(root==NULL) return 0;
        if(root!=NULL && root->left==NULL && root->right==NULL) return root->val;
        pair<int, int> mx=dfs(root);
        return max(mx.first, mx.second);
    }
};