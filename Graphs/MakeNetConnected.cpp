// the minimum number of times to make all the computers connected : all computers should be reached using min no. of cables => MST without the compulsion of removing all cycles
// MST conversion possible only when vertices = n and edges (size of connections) = n-1 (minimum)
// once MST is possible, return count of connected components - 1 

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& vis)
    {
        vis[node]=1;
        for(int adj: adjList[node])
        {
            if(!vis[adj])
                dfs(adj, adjList, vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int e=connections.size();
        if(e < n-1) return -1;

        int count=0;
        vector<vector<int>> adjList(n);
        for(auto x: connections)
        {
            adjList[x[0]].push_back(x[1]);
            adjList[x[1]].push_back(x[0]);
        }
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(i, adjList, vis);
                count++;
            }
        }
        return count-1;
    }
};
