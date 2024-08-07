class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0,0}});
        vector<vector<int>> mnPath(n, vector<int>(n, INT_MAX));
        mnPath[0][0]=1;
        
        vector<int> dx={-1,-1,-1,0,0,1,1,1};
        vector<int> dy={-1,0,1,-1,1,-1,0,1};

        while(!q.empty())
        {
            int i=q.front().second.first;
            int j=q.front().second.second;
            int dist=q.front().first;
            q.pop();

            for(int k=0; k<8; k++)
            {
                int x=i+dx[k], y=j+dy[k];
                if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==0 && dist+1<mnPath[x][y])
                {
                    mnPath[x][y]=dist+1;
                    q.push({dist+1, {x, y}});
                }
            }
        }
        return mnPath[n-1][n-1]==INT_MAX ? -1 : mnPath[n-1][n-1];
    }      
};
