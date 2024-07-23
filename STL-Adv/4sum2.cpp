class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        for(auto x:nums1)
        {
            for(auto y:nums2) //no other optimal approach
            {
                mp[x+y]++;
            }
        }
        int count=0, sum;
        for(auto x:nums3)
        {
            for(auto y:nums4)
            {
                sum=x+y;
                count+=mp[-sum]; //resultant sum=0 iff c+d=-(a+b)
            }
        }       
        return count;
    }
};