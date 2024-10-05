/*
Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
A pair (i, j) is fair if:
  0 <= i < j < n, and
  lower <= nums[i] + nums[j] <= upper
*/

class Solution {
public:
    long long lb(vector<int>& nums, int start, int end, int val)
    {
        long long ans=end+1;
        while(start<=end)
        {
            long long mid=start+(end-start)/2;
            if(val<=nums[mid])
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
    long long ub(vector<int>& nums, int start, int end, int val)
    {
        long long ans=end+1;
        while(start<=end)
        {
            long long mid=start+(end-start)/2;
            if(val<nums[mid])
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;

    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        long long cnt=0;
        for(int i=0; i<n; i++)
        {
            int low=lb(nums, i+1, n-1, lower-nums[i]);
            int high=ub(nums, i+1, n-1, upper-nums[i]);
            cnt+=(high-low);
        }
        return cnt;
    }
};
