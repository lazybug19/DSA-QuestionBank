//BS
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(int i=0; i<nums.size(); i++)
        {
            int n=lis.size();
            if(n==0 || lis[n-1]<nums[i])
                lis.push_back(nums[i]);
            else
            {
                auto idx=lower_bound(lis.begin(), lis.end(), nums[i]);
                *idx=nums[i];
            }
        }
        return lis.size();
    }
};

//DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(), res=INT_MIN;
        vector<int> dp(n+1, 1);
        for(int c=0; c<n; c++)
        {
            for(int p=0; p<c; p++)
            {
                if(nums[c]>nums[p])
                    dp[c]=max(dp[c], 1+dp[p]);
            }
            res=max(res, dp[c]);
        }
        return res;
    }
};