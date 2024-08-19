class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<int> vis(V, 0);
        int mstWt=0;
        while(!pq.empty())
        {
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(!vis[node])
            {
                vis[node]=1;
                for(auto x: adj[node])
                    pq.push({x[1], x[0]});
                mstWt+=wt;
            }
        }
        return mstWt;
    }
};
