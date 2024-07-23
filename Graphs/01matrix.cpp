class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> dist(n, vector<int>(m,0));
        queue<pair<pair<int,int>, int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0;  j<m; j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j}, 0});
                    vis[i][j]=1;
                }
            }
        }
        vector<int> row, col;
        row = {0, 1, 0, -1};
        col = {1, 0, -1, 0};
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int step=q.front().second;
            q.pop();
            dist[r][c]=step;
            for(int i=0; i<4; i++)
            {
                int rn = r+row[i];
                int cn = c+col[i];
                if(rn>=0 && rn<n && cn>=0 && cn<m && vis[rn][cn]==0)
                {
                    vis[rn][cn]=1;
                    q.push({{rn,cn}, step+1});
                }
            }
        }
        return dist;
    }
};