// Brute Force : O(n) solution via any DFS/BFS traversal

// O(log(n)) approach:

// Hint - perfect binary tree : total nodes = 2^h - 1
class Solution {
public:
    int leftCount(TreeNode* root)
    {
        int ht=0;
        while(root)
        {
            ht++;
            root=root->left;
        }
        return ht;
    }
    int rightCount(TreeNode* root)
    {
        int ht=0;
        while(root)
        {
            ht++;
            root=root->right;
        }
        return ht;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lc=leftCount(root);
        int rc=rightCount(root);

        if(lc==rc) // perfect binary tree
            return (1<<lc)-1; // (2^h)-1

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
