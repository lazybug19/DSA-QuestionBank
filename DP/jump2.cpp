class Solution {
public:
    int solve(vector<int>& dp, vector<int>& nums, int i)
    {
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int mn=nums.size()-1;
        for(int j=1; j<=nums[i]; j++)
        {
            int count=1+solve(dp, nums, i+j);
            mn=min(mn, count);
        }
        return dp[i]=mn;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return solve(dp, nums, 0);
    }
};
