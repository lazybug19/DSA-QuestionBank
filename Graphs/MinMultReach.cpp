
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // if a priority queue is used for min steps, then it will be like running after 
        // min steps and not reach the required product
        
        // also queue's fifo helps in keeping track of all possible products of initial prod

        queue<pair<int, int>> q; //{product so far, steps so far}
        q.push({start, 0});
        vector<int> dist(100000, INT_MAX);
        dist[start]=0;
        
        while(!q.empty())
        {
            int prod=q.front().first;
            int steps=q.front().second;
            q.pop();
            
            if(prod==end) return steps;
            
            for(int x: arr)
            {
                int n=(prod*x)%100000;
                if(steps+1 < dist[n])
                {
                    dist[n]=steps+1;
                    if(n==end) return dist[n];
                    q.push({n, dist[n]});
                }
            }
        }
        
        return -1;
    }
};
