class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjList(n);
        for(auto x: flights)
            adjList[x[0]].push_back({x[1], x[2]});
        queue<pair<int, pair<int, int>>> q; //{stops, {node, dist}}
        vector<int> mnDist(n, INT_MAX);
        mnDist[src]=0;
        q.push({0, {src, 0}});
        while(!q.empty())
        {
            int stops=q.front().first;
            int node=q.front().second.first;
            int dist=q.front().second.second;
            q.pop();

            if(stops>k) continue;
            for(auto x: adjList[node])
            {
                if(x.second+dist<mnDist[x.first])
                {
                    mnDist[x.first]=x.second+dist;
                    q.push({stops+1, {x.first, x.second+dist}});
                }
            }
        }
        return mnDist[dst]==INT_MAX ? -1 : mnDist[dst];
    }
};
