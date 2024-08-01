class Solution {
public:
    int dpSol(int i,int sell,int n, vector<int>& prices,vector<vector<int>>& dp, int fee){
        if(i==n) return 0;
        if(dp[i][sell]!=-1) return dp[i][sell];
        if(sell==0) //buy
            dp[i][sell] = max(-prices[i]+ dpSol(i+1,1,n,prices,dp,fee), dpSol(i+1,0,n,prices,dp,fee));
        else //sell
            dp[i][sell] = max(prices[i]-fee+ dpSol(i+1,0,n,prices,dp,fee), dpSol(i+1,1,n,prices,dp,fee));
        return dp[i][sell];
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return dpSol(0,0,n,prices,dp, fee);
    }
};
