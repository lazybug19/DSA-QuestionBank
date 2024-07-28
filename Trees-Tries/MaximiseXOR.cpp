class Node {
public:
    Node* links[2]; //0 or 1

    bool containsBit(int i)
    {
        return links[i]!=NULL;
    }

    Node* get(int i)
    {
        return links[i];
    }

    void add(int i, Node* node)
    {
        links[i] = node;
    }
};

class Trie {
public:
    Node* root;
    Trie()
    {
        root=new Node();
    }

    void insert(int n)
    {
        Node* node=root;
        for(int i=31; i>=0; i--)
        {
            int bit=(n>>i)&1;
            if(!node->containsBit(bit))
            {
                node->add(bit, new Node());
            }
            node=node->get(bit);
        }
    }

    int maxXOR(int n)
    {
        Node* node=root;
        int res=0;
        for(int i=31; i>=0; i--)
        {
            int bit=(n>>i)&1;
            if(node->containsBit(1-bit))
            {
                res |= (1<<i);
                node=node->get(1-bit);
            }
            else
                node=node->get(bit);
        }
        return res;
    }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int x: nums) trie.insert(x);
        priority_queue<int> pq;
        for(int x: nums)
        {
            int xr=trie.maxXOR(x);
            pq.push(xr);
        }
        return pq.top();
    }
};
