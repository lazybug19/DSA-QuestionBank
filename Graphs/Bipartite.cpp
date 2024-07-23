class Solution {
public:
    // -1: uncoloured, 1: black, 0: white
    bool dfs(int root, vector<vector<int>>& graph, int col, vector<int>& colors)
    {
        colors[root] = col;
        for(auto node: graph[root])
        {
            if(colors[node]==-1)
            {
                if(dfs(node, graph, !col, colors)==false) return false;
            }
            else
            {
                if(colors[node]==col) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> colors(v, -1);
        for(int i=0; i<v; i++)
        {
            if(colors[i]==-1)
            {
                if(dfs(i, graph, 0, colors)==false)
                    return false;
            }
        }
        return true;
    }
};