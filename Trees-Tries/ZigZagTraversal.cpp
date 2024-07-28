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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true; //L to R
        
        while(!q.empty())
        {
            int n=q.size();
            vector<int> row(n);
            for(int i=0; i<n; i++)
            {
                int idx = flag ? i : n-1-i;
                TreeNode* frNode = q.front();
                q.pop();

                row[idx]=frNode->val;
                
                if(frNode->left)
                    q.push(frNode->left);
                if(frNode->right)
                    q.push(frNode->right);
            }
            res.push_back(row);
            flag=!flag;
        }
        return res;
    }
};
