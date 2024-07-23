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
    vector<int> postorderTraversal(TreeNode* curr) {
        vector < int > v;
        if (curr == NULL) return v;

        stack < TreeNode * > s1;
        stack < TreeNode * > s2;
        s1.push(curr);
        while (!s1.empty()) {
            curr = s1.top();
            s1.pop();
            s2.push(curr);
            if (curr -> left != NULL)
            s1.push(curr -> left);
            if (curr -> right != NULL)
            s1.push(curr -> right);
        }
        while (!s2.empty()) {
            v.push_back(s2.top() -> val);
            s2.pop();
        }
  return v;
    }
};