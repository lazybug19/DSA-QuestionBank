/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each 
integer appears at most twice, return an array of all the integers that appears twice.
*/

// O(n) time and O(1) space
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        for(int i=0; i<n; i++)
        {
            int idx=abs(nums[i])-1;
            if(nums[idx]<0) res.push_back(abs(nums[i]));
            else nums[idx]*=-1;
        }
        return res;
    }
};
