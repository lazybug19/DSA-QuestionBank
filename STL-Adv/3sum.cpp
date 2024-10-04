/*
  Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, 
  and j != k, and nums[i] + nums[j] + nums[k] == 0. Notice that the solution set must not contain duplicate
  triplets.
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            int j = i + 1, k = n - 1;
            while (j < k) 
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        vector<vector<int>> v(s.begin(), s.end());
        return v;
    }
};
