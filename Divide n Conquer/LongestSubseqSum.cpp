/*
  Return an array answer of length m where answer[i] is the maximum size of a subsequence that you can take from 
  nums such that the sum of its elements is less than or equal to queries[i].
*/

class Solution {
public:
    int bs(vector<int>& preSum, int target)
    {
        int start=0, end=preSum.size()-1, ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(preSum[mid]<=target)
            {
                ans=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        return ans+1;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // relative order does not matter when doing summation of subsequence elements
        vector<int> preSum(nums.size(), 0), res;
        sort(nums.begin(), nums.end());
        preSum[0]=nums[0];
        for(int i=1; i<nums.size(); i++) preSum[i]=preSum[i-1]+nums[i];
        for(int x: queries) res.push_back(bs(preSum, x));
        return res;
    }
};
