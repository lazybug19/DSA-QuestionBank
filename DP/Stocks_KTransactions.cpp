class Solution {
public:
    int dpSol(int i, int n, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp)
    {
        if(i==n || k==0) return 0;
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        if(buy==0)
           dp[i][buy][k] = max(dpSol(i+1, n, 0, k, prices, dp), dpSol(i+1, n, 1, k, prices, dp)-prices[i]);
        else
           dp[i][buy][k] = max(dpSol(i+1, n, 1, k, prices, dp), dpSol(i+1, n, 0, k-1, prices, dp)+prices[i]);
        return dp[i][buy][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return dpSol(0, n, 0, k, prices, dp);
    }
};

