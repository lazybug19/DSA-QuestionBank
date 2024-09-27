/*
Given an array of integers. Find the Reverse Count in the array.  
Two array elements arr[i] and arr[j] form a reverse pair if arr[i] > 2*arr[j] and i < j.
*/


class Solution {
public:
    void merge(vector<int>& nums, long long l, long long mid, long long r)
    {
        long long lptr=l, rptr=mid+1;
        vector<int> temp;
        while(lptr<=mid && rptr<=r)
        {
            if(nums[lptr]<=nums[rptr])
            {
                temp.push_back(nums[lptr]);
                lptr++;
            }
            else
            {
                temp.push_back(nums[rptr]);
                rptr++;
            }
        }
        while(lptr<=mid)
        {
            temp.push_back(nums[lptr]);
            lptr++;
        }
        while(rptr<=r)
        {
            temp.push_back(nums[rptr]);
            rptr++;
        }
        for(long long i=l; i<=r; i++)
            nums[i]=temp[i-l];
    }
    long long countPairs(vector<int>& nums, long long l, long long mid, long long r)
    {
        long long cnt=0, lptr=l, rptr=mid+1;
        while(lptr<=mid)
        {
            while(rptr<=r && nums[lptr]>2*(long)nums[rptr]) rptr++;
            cnt+=(rptr-mid-1);
            lptr++;
        }
        return cnt;
    }
    long long mergeSort(vector<int>& nums, long long l, long long r)
    {
        long long cnt=0;
        if(l>=r) return cnt;
        long long mid=l+(r-l)/2;
        cnt+=mergeSort(nums, l, mid);
        cnt+=mergeSort(nums, mid+1, r);
        cnt+=countPairs(nums, l, mid, r);
        merge(nums, l, mid, r);
        return cnt;

    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
