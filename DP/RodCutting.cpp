class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> dp(n+1);
        dp[0]=0;
        for(int i=1; i<n+1; i++) //req length of rod
        {
            for(int j=1; j<=i; j++) //length we pick j+1
            {
                dp[i] = max(price[j-1]+dp[i-j], dp[i]);
            }
        }
        return dp[n];
    }
};