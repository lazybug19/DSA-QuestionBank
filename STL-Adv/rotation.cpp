//rotation by x times
An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size(), j = n;
        while(j<2*n)
        {
            nums.push_back(0);
            j++;
        }
        for(int i=0; i<n; i++)
            nums[(i+k)%n + n] = nums[i];
        nums.erase(nums.begin(), nums.begin()+n);
    }
};


//for second largest and smallest
for(i=0;i<n;i++)
    {
        if(arr[i]<second_small && arr[i]!=small)
            second_small=arr[i];
        if(arr[i]>second_large && arr[i]!=large)
            second_large=arr[i];
    }