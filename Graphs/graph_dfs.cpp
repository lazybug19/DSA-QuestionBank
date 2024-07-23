#include <bits/stdc++.h>
using namespace std;

void dfs(int n, vector<int> &vis, vector<int> &res, vector<vector<int>> &v)
{
    vis[n]=1;
    res.push_back(n);
    for(auto x: v[n])
    {
        if(vis[x]==0)
            dfs(x,vis,res,v);
    }
}

void addEdge(vector<vector<int>> &v, int x, int y)
{
    v[x].push_back(y);
    v[y].push_back(x);
}
int main()
{
    vector<vector<int>> v(9);
    addEdge(v,1,2);
    addEdge(v,2,5);
    addEdge(v,1,3);
    addEdge(v,3,4);
    addEdge(v,3,7);
    addEdge(v,4,8);
    addEdge(v,8,7);
    addEdge(v,6,2);
    
    vector<int> vis(9,0);
    vector<int> res;
    dfs(1, vis, res, v);
    
    cout<<res[0]<<res[1]<<res[2]<<res[3]<<res[4]<<res[5]<<res[6]<<res[7];
    
    return 0;
}