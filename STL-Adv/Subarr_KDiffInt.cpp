// Given an integer array nums and an integer k, return the number of good subarrays of nums.
// A good array is an array where the number of different integers in that array is exactly k.


class Solution {
public:
    int kCount(vector<int>& nums, int k)
    {
        int n=nums.size(), i=0, j=0, count=0;
        unordered_map<int,int> mp;
        while(i<n)
        {
            mp[nums[i]]++;
            while(mp.size()>k)
            {
                mp[nums[j]]--;
                if(mp[nums[j]]==0)
                    mp.erase(nums[j]);
                j++;
            }
            count+=i-j+1;
            i++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return kCount(nums, k)-kCount(nums, k-1);
        // return kCount(nums, k)
        // when kCount has if(mp.size()==k) count+=i-j+1;
        // doesn't work
    }
};
