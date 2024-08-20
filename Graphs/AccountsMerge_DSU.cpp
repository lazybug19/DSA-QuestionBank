class Solution {
public:
    int findPar(int node, vector<int>& par)
    {
        if(par[node]==node) return node;
        return par[node]=findPar(par[node], par);
    }

    void unionBySize(int u, int v, vector<int>& par, vector<int>& size)
    {
        int pu=findPar(u, par);
        int pv=findPar(v, par);
        if(pu==pv) return;
        if(size[pu]<size[pv])
        {
            par[pu]=pv;
            size[pv]+=size[pu];
        }
        else
        {
            par[pv]=pu;
            size[pu]+=size[pv];
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        int i=0, n=accounts.size();
        sort(accounts.begin(), accounts.end());
        vector<int> par(n);
        for(int i=0; i<n; i++) par[i]=i;
        vector<int> size(n, 1);

        for(int i=0; i<n; i++)
        {
            auto x = accounts[i];
            for(int j=1; j<x.size(); j++)
            {
                string s=x[j];
                if(mp.find(s)==mp.end())
                    mp[s]=i;
                else
                    unionBySize(i, mp[s], par, size);
            }
        }

        vector<vector<string>> merged(n);
        for(auto x: mp)
        {
            int up=findPar(x.second, par);
            merged[up].push_back(x.first);
        }

        vector<vector<string>> res;
        for(int i=0; i<n; i++)
        {
            if(merged[i].size()!=0)
            {
                vector<string> v;
                v.push_back(accounts[i][0]);
                sort(merged[i].begin(), merged[i].end());
                for(string s: merged[i])
                    v.push_back(s);
                res.push_back(v);
            }
        }
        return res;
    }
};
