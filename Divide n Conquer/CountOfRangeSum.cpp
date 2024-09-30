/*
  Given an integer array nums and two integers lower and upper, return the number of range sums that lie in 
  [lower, upper] inclusive.
*/

class Solution {
public:
    int cnt=0, l=0, u=0;
    void merge(vector<long long>& preSum, int left, int mid, int right)
    {
        vector<long long> temp;
        int lstart=left, rstart=mid+1;
        while(lstart<=mid && rstart<=right)
        {
            if(preSum[lstart]<=preSum[rstart])
            {
                temp.push_back(preSum[lstart]);
                lstart++;
            }
            else
            {
                temp.push_back(preSum[rstart]);
                rstart++;
            }
        }
        while(lstart<=mid)
        {
            temp.push_back(preSum[lstart]);
            lstart++;
        }
        while(rstart<=right)
        {
            temp.push_back(preSum[rstart]);
            rstart++;
        }
        for(int i=left; i<=right; i++)
            preSum[i]=temp[i-left];
    }
    int countRange(int left, int mid, int right, vector<long long>& preSum)
    {
        int lstart=left, rstart=mid+1, rend=mid+1;
        while(lstart<=mid)
        {
            while(rstart<=right && preSum[rstart]-preSum[lstart] < l)
                rstart++;
            while(rend<=right && (preSum[rend]-preSum[lstart]) <= u)
                rend++;
            cnt+=(rend-rstart);
            lstart++;
        }
        return cnt;
    }
    void mergeSort(vector<long long>& preSum, int left, int right)
    {
        if(left>=right) return;
        int mid=left+(right-left)/2;
        mergeSort(preSum, left, mid);
        mergeSort(preSum, mid+1, right);
        countRange(left, mid, right, preSum);
        merge(preSum, left, mid, right);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        l=lower, u=upper;
        if(n==0) return 0;
        vector<long long> preSum(n+1, 0);
        for(int i=0; i<n; i++)
            preSum[i+1]=preSum[i]+(long long)nums[i];
        mergeSort(preSum, 0, n);        
        return cnt;
    }
};
