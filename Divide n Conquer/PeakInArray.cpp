/*
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks,
return the index to any of the peaks. You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is 
always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || nums[0]>nums[1]) return 0; // edge case 1: first element is peak
        if(nums[n-1]>nums[n-2]) return n-1; // edge case 2: last element is peak
        int f=1,l=n-2,mid;
        while(f<=l)
        {
            mid=(f+l)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) 
                return mid;
            if(nums[mid]>=nums[mid-1])
                f=mid+1;
            else 
                l=mid-1;
        }
        return -1;        
    }
};                                             
