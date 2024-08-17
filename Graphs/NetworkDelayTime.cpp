class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n+1);
        for(auto x : times)
        {
            adjList[x[0]].push_back({x[1], x[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mn; //mn heap
        vector<int> time(n+1, INT_MAX);
        time[k]=0;
        mn.push({0, k});
        while(!mn.empty())
        {
            int node=mn.top().second;
            int tm=mn.top().first;
            mn.pop();
            for(auto x: adjList[node])
            {
                if(x.second+tm < time[x.first])
                {
                    time[x.first] = x.second+tm;
                    mn.push({time[x.first], x.first});
                }
            }
        }
        int mx=INT_MIN;
        for(int i=1; i<=n; i++) 
        {
            if(i!=k && time[i]==INT_MAX) return -1;
            mx=max(time[i], mx);
        }
        return mx;
    }
};
