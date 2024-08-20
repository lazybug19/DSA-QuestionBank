#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, int parent, vector<vector<int>> &v, vector<int>& vis)
{
    vis[i]=1;
    for(auto child: v[i])//i -> parent
    {
        if(vis[child]!=1)
        {
            dfs(child,i,v,vis);
            /*if(dfs(child,i,v,vis)) return true*/
        }
        else
        {
            if(i!=child)
                return true;
        }
    }
    return false;
}
void addEdge(vector<vector<int>> &v, int x, int y)
{
    v[x].push_back(y);
    v[y].push_back(x);
}
bool detectCycle()
{
    vector<vector<int>> v(5); //nodes+1
    vector<int> vis(n,0);
    addEdge(v,1,2);
    addEdge(v,0,1);
    addEdge(v,1,3);
    addEdge(v,0,4);
    for(int i=0; i<5; i++)
    {
        if(vis[i]!=1)
        {
            if(dfs(i,-1,v,vis))
                return true; // if there is 1 cycle even;
        }
    } 
    return false;
}
