class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0; 
        
        int lh = maxDepth(root->left); 
        int rh = maxDepth(root->right); 
        
        return 1 + max(lh, rh); 
    }
};

//OR

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