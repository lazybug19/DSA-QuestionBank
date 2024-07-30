//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Node {
public:
    Node* letters[26];
    bool flag=false;
    
    bool containsL(char c)
    {
        return letters[c-'a']!=NULL;
    }
    
    void add(char c, Node* node)
    {
        letters[c-'a'] = node;
    }
    
    Node* find(char c)
    {
        return letters[c-'a'];
    }
    
    void setFlag()
    {
        flag=true;
    }
    
    bool getFlag()
    {
        return flag;
    }
};

class Trie {
public:
    Node* root;
    Trie()
    {
        root = new Node();
    }
    
    void insert(string s)
    {
        Node* node=root;
        for(int i=0; i<s.length(); i++)
        {
            if(!node->containsL(s[i]))
                node->add(s[i], new Node());
            node=node->find(s[i]);
        }
        node->setFlag();
    }
    
    bool findString(string s)
    {
        Node* node=root;
        for(int i=0; i<s.length(); i++)
        {
            if(!node->containsL(s[i]))
                return false;
            node=node->find(s[i]);
        }
        return node->getFlag();
    }
};


class Solution {
public:
    string longestString(vector<string> &words)
    {
        Trie trie;
        for(string word: words) trie.insert(word);
        int mx=INT_MIN;
        string res;
        for(string word: words)
        {
            int i, n=word.length();
            for(i=0; i<n-1; i++)
            {
                string s=word.substr(0, i+1);
                if(!trie.findString(s)) break;
            }
            if(i==n-1) 
            {   
                if (n > mx || (n == mx && word < res)) {
                    mx = n;
                    res = word;
                }
            }
        }
        return res;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends
