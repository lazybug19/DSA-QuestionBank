class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int f=0, l=nums.size()-1, mid;
        while(f<=l)
        {
            mid=(f+l)/2;
            if(target==nums[mid])
                return true;
            if(nums[mid]==nums[f] && nums[mid]==nums[l]) //edge case
            {
                l--;
                f++;
                continue;
            }
            if(nums[f]<=nums[mid])
            {
                if(target>=nums[f] && target<=nums[mid])
                    l=mid-1;
                else
                    f=mid+1;
            }
            else
            {
                if(target<=nums[l] && target>=nums[mid])
                    f=mid+1;
                else
                    l=mid-1;
            }
        }
        return false;        
    }
};