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
  
  bool isValid(int x, int y, int n, int m)
  {
    return x>=0 && x<n && y>=0 && y<m;
  }
  
  vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
  {
    vector<int> par(n*m);
    for(int i=0; i<n*m; i++) par[i]=i;
    vector<int> size(n*m, 1);
    
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    int r[4] = {-1, 0, 0, 1};
    int c[4] = {0, -1, 1, 0};
    vector<int> res;
    int cnt=0;
    int k=operators.size();
    for(int i=0; i<k; i++)
    {
        int row=operators[i][0];
        int col=operators[i][1];
        if(matrix[row][col]==1)
        {
            res.push_back(cnt);
            continue;
        }
        else
        {
            matrix[row][col]==1;
            cnt++;
            
            for(int j=0; j<4; j++)
            {
                int ar=row+r[j];
                int ac=col+c[j];
                if(isValid(ar, ac, n, m) && vis[ar][ac]==1)
                {
                    int ccell=row*m + col;
                    int acell=ar*m + ac;
                    if(findPar(ccell)!=findPar(acell)) // they belong to different clusters or sets
                    {
                        cnt--;
                        unionBySize(ccell, acell, par, size);
                    }
                }
                res.push_back(cnt);
            }
        }
    }
    return res;
  }
};
