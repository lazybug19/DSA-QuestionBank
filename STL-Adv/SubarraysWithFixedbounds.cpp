class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long mn=-1, mx=-1, exc=-1, cnt=0;
    for(int i=0; i<nums.size(); i++) 
    {
        if(nums[i]<minK || nums[i]>maxK) exc=i;
        if(nums[i]==minK) mn=i;
        if(nums[i]==maxK) mx=i;
        long long valid=(min(mn, mx)-exc)<0 ? 0 : min(mn, mx)-exc; 
        cnt+=valid;
    }
    return cnt;
    }
};
