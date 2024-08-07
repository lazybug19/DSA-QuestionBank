// shortest path from source to eac node acting as destination for an undirected, weighted and connected graph

class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> mnPaths(V, INT_MAX);
        mnPaths[S]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        while(!pq.empty())
        {
            int distSoFar=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto x: adj[node])
            {
                if(distSoFar + x[1] < mnPaths[x[0]])
                {
                    mnPaths[x[0]] = distSoFar + x[1];
                    pq.push({mnPaths[x[0]], x[0]});
                }
            }
        }
        
        for(int i=0; i<V; i++)
            if(mnPaths[i]==INT_MAX) mnPaths[i]=-1;
        return mnPaths;
    }
};
