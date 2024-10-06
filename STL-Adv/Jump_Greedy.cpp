/*
  You are given an integer array nums of length n. Your goal is to start at index 0 and reach index n - 1.
  You can only jump to indices greater than your current index. The score for a jump from index i to index j 
  is calculated as (j - i) * nums[i]. Return the maximum possible total score by the time you reach the last index.
*/

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long score=0, prev=nums[0], i=1, j=0;
        while(i<nums.size())
        {
            if(nums[i]>prev || i==nums.size()-1)
            {
                score+=(prev*(i-j));
                prev=nums[i];
                j=i;
            }
            i++;
        }
        return score;
    }
};
