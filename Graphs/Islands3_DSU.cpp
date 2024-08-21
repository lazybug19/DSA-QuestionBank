// Atmost 1 cell flip from 0 to 1 for largest island


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
    
    bool isValid(int x, int y, int n)
    {
        return x>=0 && x<n && y>=0 && y<n;
    }    
    
    int largestIsland(vector<vector<int>>& grid)
    {
        int r[4] = {-1, 0, 0, 1};
        int c[4] = {0, -1, 1, 0};
        int mx=0, n=grid.size();
        vector<int> par(n*n);
        for(int i=0; i<n*n; i++) par[i]=i;
        vector<int> size(n*n, 1);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    for(int k=0; k<4; k++)
                    {
                        int ar=i+r[k];
                        int ac=j+c[k];
                        if(isValid(ar, ac, n) && grid[ar][ac]==1)
                        {
                            int ccell=i*n + j;
                            int acell=ar*n + ac;
                            if(findPar(ccell, par)!=findPar(acell, par)) // no union yet
                                unionBySize(ccell, acell, par, size);
                        }
                    }
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==0)
                {
                    unordered_set<int> s;
                    int sz=1; // for 1 cell flip
                    for(int k=0; k<4; k++)
                    {
                        int ar=i+r[k];
                        int ac=j+c[k];
                        if(isValid(ar, ac, n) && grid[ar][ac]==1)
                        {
                            int acell=ar*n + ac;
                            s.insert(findPar(acell, par));
                        }
                    }
                    for(auto it: s)
                    {
                        sz+=size[it];
                    }
                    mx=max(mx, sz); 
                }
            }
        }
        for(int i=0; i<n*n; i++)
        {
            // cell no. : i
            mx=max(mx, size[findPar(i, par)]); // for 0 cell flips
        }
        return mx;
    }
};
