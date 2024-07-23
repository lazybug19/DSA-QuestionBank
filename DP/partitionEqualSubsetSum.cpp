class Solution {
public:
    bool subsetSum(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<vector<bool>> dp(n+1, vector<bool>(k+1));
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<k+1; j++)
            {
                if(i==0) 
                {
                    dp[i][j]=false;
                    continue;
                }
                if(j==0) 
                {
                    dp[i][j]=true;
                    continue;
                }
                if(nums[i-1]<=j) dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][k];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x: nums) sum+=x;
        if(sum%2 != 0) return false;
        return subsetSum(nums, sum/2);
    }
};