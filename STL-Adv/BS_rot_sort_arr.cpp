class Solution {
public:
    int search(vector<int>& nums, int target) {
        int f=0, l=nums.size()-1, mid;
        while(f<=l)
        {
            mid=(f+l)/2;
            if(target==nums[mid])
                return mid;
            if(nums[f]<=nums[mid]) //left half sorted
            {
                if(target>=nums[f] && target<=nums[mid]) //present in sorted half
                    l=mid-1;
                else
                    f=mid+1;
            }
            else //right half sorted
            {
                if(target>=nums[mid] && nums[l]>=target) //present in sorted half
                    f=mid+1;
                else
                    l=mid-1;
            }
        }
        return -1;
    }
};