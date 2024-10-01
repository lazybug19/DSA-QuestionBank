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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int mx=INT_MIN;
        while(!q.empty())
        {
            long long size=q.size(), first, last;
            for(long long i=0; i<size; i++)
            {
                auto x=q.front();
                long long idx=x.second;
                TreeNode* parent=x.first;
                q.pop();

                if(i==0) first=idx;
                if(i==size-1) last=idx;

                if(parent->left) q.push({parent->left, 2*idx});
                if(parent->right) q.push({parent->right, 2*idx+1});

            }
            long long len=last-first+1;
            mx=max(mx, (int)len);
        }
        return mx;
    }
};
