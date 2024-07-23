class Solution {
public:
    bool dfs(int root, vector<vector<int>>& adj, vector<int>& vis, vector<int>& paths, stack<int>& st)
    {
        vis[root] = 1;
        paths[root] = 1;
        for(int node: adj[root])
        {
            if(!vis[node] && dfs(node, adj, vis, paths, st)) return true;
            else if(vis[node] && paths[node]) return true;
        }
        st.push(root);
        paths[root] = 0;
        return false;        
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto prereq: prerequisites)
            adj[prereq[1]].push_back(prereq[0]);

        vector<int> vis(numCourses, 0);
        vector<int> paths(numCourses, 0);
        stack<int> st;
        for(int i=0; i<numCourses; i++)
        {
            if(!vis[i])
                if(dfs(i, adj, vis, paths, st))
                    return {};
        }

        vector<int> order;
        while(!st.empty())
        {
            order.push_back(st.top());
            st.pop();
        }
        if(order.size() == numCourses) return order;
        return {};
    }
};