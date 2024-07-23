class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0; 
        
        int lh = maxDepth(root->left); 
        int rh = maxDepth(root->right); 
        
        return 1 + max(lh, rh); 
    }
};

//level order

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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* current;
        q.push(root);
        if(root == NULL)
            return 0;
        int count = 0;
        while(!q.empty())
        {
            int n = q.size();
            while(n>0)
            {
                current = q.front();
                q.pop();
                if(current->left != NULL)
                    q.push(current->left);
                if(current->right != NULL)
                    q.push(current->right);
                n--;
            }
            count++;        
        }
        return count;
    }
};