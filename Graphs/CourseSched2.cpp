class Solution {
public:
    bool dfs(int root, vector<vector<int>>& adj, vector<int>& vis, vector<int>& paths)
    {
        vis[root] = 1;
        paths[root] = 1;
        for(int node: adj[root])
        {
            if(!vis[node] && dfs(node, adj, vis, paths)) return true;
            else if(vis[node] && paths[node]) return true;
        }
        paths[root] = 0;
        return false;        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> paths(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto preq: prerequisites)
        {
            adj[preq[1]].push_back(preq[0]);
        }
        for(int i=0; i<numCourses; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, adj, vis, paths))
                    return false;
            }
        }
        return true;
    }
};