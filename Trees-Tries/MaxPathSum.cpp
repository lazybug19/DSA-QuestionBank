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
    int findSum(TreeNode* root, int& maxSum){
        if(!root) return 0;
        int ls=max(0, findSum(root->left, maxSum));
        int rs=max(0, findSum(root->right, maxSum));

        maxSum = max(maxSum, ls+rs+root->val);

        return max(ls, rs)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        findSum(root, maxSum);
        return maxSum;
    }
};
