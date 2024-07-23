class Solution {
public:
    int findMin(vector<int>& nums) {
        int f=0, l=nums.size()-1, mid, ans=INT_MAX;
        while(f<=l)
        {
            mid=(f+l)/2;
            if(ans>nums[mid]) ans=nums[mid];
            if(nums[f]<=nums[mid]) //left sorted
            {
                if(ans>nums[f]) ans=nums[f];
                f=mid+1;
            }
            else //right sorted
            {
                if(ans>nums[f]) ans=nums[l];
                l=mid-1;
            }
        }
        return ans;
    }
};