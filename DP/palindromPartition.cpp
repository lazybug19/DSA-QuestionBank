class Solution {
public:
    int rec(string& s, int i, int j, vector<vector<int>>& dp, vector<vector<bool>>& pl)
    {
        if(i==j || pl[i][j]) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mn=INT_MAX;
        for (int k = i; k <= j; ++k) {
            if (pl[i][k]) {
                mn = min(mn, 1 + rec(s,k+1,j,dp,pl));
            }
        }
        return dp[i][j]=mn;
    }
    int minCut(string s) {
        int n=s.length();
        vector<vector<bool>> pl(n, vector<bool>(n, false));
        for(int i=0; i<n-1; i++) 
        {
            pl[i][i]=true; // len=1
            if(i<n-1 && s[i]==s[i+1]) // len=2
                pl[i][i+1]=true;
        }
        for(int k=3; k<=n; k++) // len>=3
        {
            for(int i=0; i<=n-k; i++)
            {
                int j=i+k-1;
                pl[i][j] = s[i]==s[j] && pl[i+1][j-1];
            }
        }
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return rec(s, 0, n-1, dp, pl);
    }
};