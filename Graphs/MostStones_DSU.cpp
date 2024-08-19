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
        if(pu!=pv)
        {
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
    }

    int removeStones(vector<vector<int>>& stones) {
        int mR=0, mC=0;
        for(auto it: stones)
        {
            mR=max(mR, it[0]);
            mC=max(mC, it[1]);
        }

        int n=(mR+1)+(mC+1);
        vector<int> par(n);
        for(int i=0; i<n; i++) par[i]=i;
        vector<int> size(n, 1);

        unordered_map<int, int> mp;
        for(auto it: stones)
        {
            int row=it[0];
            int col=it[1]+mR+1;
            unionBySize(row, col, par, size);
            mp[row]=1;
            mp[col]=1;
        }

        int cnt=0;
        for(auto it: mp)
        {
            if(findPar(it.first, par)==it.first)
                cnt++;
        }
        return stones.size()-cnt;
    }
};
