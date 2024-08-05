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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> space;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty())
        {
            TreeNode* node=q.front().first;
            int v=q.front().second.first;
            int l=q.front().second.second;
            q.pop();

            if(node) space[v][l].insert(node->val);
            if(node->left) q.push({node->left, {v-1, l+1}});
            if(node->right) q.push({node->right, {v+1, l+1}});
        }

        vector<vector<int>> res;
        for(auto v: space)
        {
            vector<int> col;
            for(auto l: v.second)
            {
                col.insert(col.end(), l.second.begin(), l.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
};
