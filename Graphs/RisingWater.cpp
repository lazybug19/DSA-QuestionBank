// Q. https://leetcode.com/problems/swim-in-rising-water/

class Solution {
public:
    bool isValid(int x, int y, int n)
    {
        return x>=0 && x<n && y>=0 && y<n;
    }

    bool validPath(int x, int y, int n, vector<vector<int>>& vis, vector<vector<int>>& grid, int t, int r[], int c[])
    {
        vis[x][y]=1;
        if(x==n-1 && y==n-1) return true;
        for(int i=0; i<4; i++)
        {
            int ax=x+r[i];
            int ay=y+c[i];
            if(isValid(ax, ay, n) && vis[ax][ay]==0 && grid[ax][ay]<=t)
            {
                if(validPath(ax, ay, n, vis, grid, t, r, c)==true) return true;
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int ans=0, n=grid.size();
        int r[4] = {1, -1, 0, 0};
        int c[4] = {0, 0, 1, -1};
        int f=0, l=n*n-1;
        while(f<=l)
        {
            int mid=f+(l-f)/2;
            vector<vector<int>> vis(n+1 , vector<int>(n+1  , 0));
            if(grid[0][0]<=mid && validPath(0, 0, n, vis, grid, mid, r, c))
            {
                ans=mid;
                l=mid-1;
            }
            else
            {
                f=mid+1;
            }
        }
        return ans;
    }
};
