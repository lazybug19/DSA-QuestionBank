#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* letters[26];
    bool flag = false;
    
    bool containsKey(char c)
    {
        if(letters[c-'a']==NULL)
            return false;
        return true;
    }
    void assign(char c, Node* node) 
    {
        letters[c-'a'] = node;
    }
    Node* get(char c)
    {
        return letters[c-'a'];
    }
    void end() 
    {
        flag = true;
    } 
    bool check() 
    {
        return flag;
    }
};

class Trie{
public:
    Node* root = new Node();
    void insert(string word)
    {
        Node* ref= root;
        for(int i=0; i<word.size(); i++)
        {
            if(!ref->containsKey(word[i]))
                ref->assign(word[i], new Node());
            ref = ref->get(word[i]);
        }
        ref->end();
    }
    
    bool search(string word)
    {
        Node* ref= root;
        for(int i=0; i<word.size(); i++)
        {
            if(!ref->containsKey(word[i]))
                return false;
            ref = ref->get(word[i]);
        }
        if(ref->check()) return true;
        return false;
    }
    
    bool prefixSearch(string prefix)
    {
        Node* ref= root;
        for(int i=0; i<prefix.size(); i++)
        {
            if(!ref->containsKey(prefix[i]))
                return false;
            ref = ref->get(prefix[i]);
        }
        return true;
    }
};

int main()
{
    Trie obj;
    obj.insert("apple");
    obj.insert("apps");
    obj.insert("appxl");
    cout << obj.search("apple") <<endl;
    cout << obj.prefixSearch("app") << endl;
    cout << obj.search("appk");
    return 0;
}