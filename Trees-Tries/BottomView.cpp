class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> res;
        map<int, int> s;
        queue<pair<Node*, int>> q;
        if(!root) return res;
        q.push({root, 0});
        while(!q.empty())
        {
            Node* node=q.front().first;
            int pos=q.front().second;
            q.pop();
            
            s[pos] = node->data;
            
            if(node->left)
                q.push({node->left, pos-1});
            if(node->right)
                q.push({node->right, pos+1});
        }
        
        for(auto x: s)  res.push_back(x.second);
        return res;
    }
};
