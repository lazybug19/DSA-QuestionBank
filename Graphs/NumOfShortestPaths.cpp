class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod=1e9+7;
        vector<vector<pair<int, int>>> adjList(n);
        for(auto x: roads)
        {
            adjList[x[0]].push_back({x[1], x[2]});
            adjList[x[1]].push_back({x[0], x[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, 1e12);
        vector<long long> ways(n, 0);
        pq.push({0, 0});
        dist[0]=0;
        ways[0]=1;

        while(!pq.empty())
        {
            long long prev=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto x: adjList[node])
            {
                if(prev+x.second < dist[x.first])
                {
                    dist[x.first] = prev+x.second;
                    pq.push({dist[x.first], x.first});
                    ways[x.first]=ways[node]%mod;
                }
                else if(prev+x.second == dist[x.first])
                {
                    ways[x.first]+=(ways[node])%mod;
                }

            }
        }
        return ways[n-1]%mod;
    }
};
