//You are given an integer array nums. You are initially positioned at the array's first index, 
// and each element in the array represents your maximum jump length at that position.
//Return true if you can reach the last index, or false otherwise.
class Solution {
public:
    bool canJump(vector<int>& nums) {
    int n = nums.size(), maxReach = 0;
    for (int i = 0; i < n; i++) {
        // i <= maxReach implies prev maxReach can atleast cover or reach i
        if (i > maxReach) return false; // implies maxReach cannot reach next i let alone last index
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
    }
};
