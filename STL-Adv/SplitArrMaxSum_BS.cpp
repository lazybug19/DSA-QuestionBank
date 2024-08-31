/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any 
subarray is minimized. Return the minimized largest sum of the split.
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int mn=INT_MIN, mx=0;
        for(int x: nums)
        {
            mn=max(x, mn);
            mx+=x;
        }
        while(mn<=mx)
        {
            int mid=mn+(mx-mn)/2, sum=0, cnt=1;
            for(int x: nums)
            {
                if(sum+x<=mid)
                    sum+=x;
                else
                {
                    cnt++;
                    sum=x;
                }
            }
            if(cnt<=k)
                mx=mid-1;
            else
                mn=mid+1;
        }
        return mn;
    }
};
