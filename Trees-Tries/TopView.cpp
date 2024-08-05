//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
class Solution
{
    public:
    vector<int> topView(Node *root)
    {
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
            
            if(s.find(pos)==s.end())
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



//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
