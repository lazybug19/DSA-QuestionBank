#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int>& vis, vector<vector<int>>& v)
{
    vis[i]=1;
    for(auto x: v[i])
    {
        if(vis[x]!=1)
            dfs(x,vis,v);
    }
}
void addEdge(vector<vector<int>> &v, int x, int y)
{
    v[x].push_back(y);
    v[y].push_back(x);
}
int main()
{
    int count=0;
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
    for(int i=0; i<9; i++)
    {
        if(vis[i]!=1)
        {
            dfs(1, vis, v);
            count++;
        }
    }
    cout<<count;
    
    return 0;
}