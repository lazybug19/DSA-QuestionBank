#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &v, int n)
{
    queue<int> q;
    vector<int> res;
    vector<int> vis(n,0);
    vis[0]=1;
    q.push(0);
    while(!q.empty())
    {
        int m=q.front();
        q.pop();
        res.push_back(m);
        for(auto x : v[m])
        {
            if(vis[x] == 0)
            {
                vis[x] = 1;
                q.push(x);
            }
        }
    }
    return res;
}
void addEdge(vector<vector<int>> &v, int x, int y)
{
    v[x].push_back(y);
    v[y].push_back(x);
}
int main()
{
    vector<vector<int>> v(5); //nodes+1
    addEdge(v,1,2);
    addEdge(v,0,1);
    addEdge(v,1,3);
    addEdge(v,0,4);
    
    vector<int> f = bfs(v, 5);
    cout << f[0] << f[1] << f[2] << f[3] << f[4];
}