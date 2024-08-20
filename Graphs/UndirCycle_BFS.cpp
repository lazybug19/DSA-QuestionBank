#include <bits/stdc++.h>
using namespace std;

bool bfs(int i, vector<vector<int>> &v, vector<int>& vis)
{
    queue<pair<int,int> q;
    vis[i]=1;
    q.push({i,-1}); //{child,parent}
    while(!q.empty())
    {
        int child=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto x : v[child])
        {
            if(vis[x]!=1)
            {
                vis[x] = 1;
                q.push({x,child});
            }
            else
            {
                if(parent!=x)
                    return true;
            }
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
            if(bfs(i,v,vis))
                return true; // if there is 1 cycle even;
        }
    } 
    return false;
}
