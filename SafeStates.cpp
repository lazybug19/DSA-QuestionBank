// safe states equivalent nodes neither in cycle nor connected to cycle, so apply topo sort

// toposort using dfs:
class Solution {
public:
    bool dfs(int root, vector<vector<int>>& graph, vector<int>& vis, vector<int>& paths, stack<int>& st)
    {
        vis[root] = 1;
        paths[root] = 1;
        for(int node: graph[root])
        {
            if(!vis[node] && dfs(node, graph, vis, paths, st)) return true;
            else if(vis[node] && paths[node]) return true;
        }
        st.push(root); //it will move to this point only when no cycle exists and thus no return statements
        paths[root] = 0;       
        return false; 
    }
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
	{
        int n=graph.size();
        vector<int> vis(n, 0);
        vector<int> paths(n, 0);
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
                dfs(i, graph, vis, paths, st);
        }

        vector<int> res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        sort(res.begin(), res.end());
	    return res;
	}
};


    

    
