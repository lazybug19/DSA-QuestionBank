//Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) such that: 0 <= i < j <= n - 1 and nums[i] * nums[j] is divisible by k.

//The smallest number which should be multiplied with nums[i] so that the product is divisible by k is k / gcd(k, nums[i]). Now think about how you can store and update the count of such numbers present in the array efficiently.

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        map<long long, int> mp;
        long long count=0, gcdVal;
        for(int i=0; i<nums.size(); i++)
        {
            gcdVal = gcd(nums[i], k);
            for(auto x: mp)
            {
                if((gcdVal*x.first)%k==0)
                    count+=x.second;
            }
            //not placed before iterating map as it will count extra pairs for 0-indexed element
            mp[gcdVal]++;
        }
        return count;
    }
};