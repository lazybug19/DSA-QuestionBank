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
            if(node->containsBit(!bit))
            {
                res |= (1<<i);
                node=node->get(!bit);
            }
            else
                node=node->get(bit);
        }
        return res;
    }

};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; //min heap
        int i=0;
        for(auto x: queries)
        {
            pq.push({x[1], {x[0], i}});
            i++;
        }
        vector<int> res(queries.size(), -1);
        sort(nums.begin(), nums.end());
        int j=0, n=nums.size();
        while(!pq.empty())
        {
            int lim=pq.top().first;
            int idx=pq.top().second.second;
            int x=pq.top().second.first;
            pq.pop();
            while(nums[j]<=lim && j<n)
            {
                trie.insert(nums[j]);
                j++;
            }
            if(j!=0)
                res[idx]=trie.maxXOR(x);
            else
                res[idx]=-1;
        }
        return res;
    }
};
