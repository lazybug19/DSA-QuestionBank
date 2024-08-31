/*
  Given an array a of length n and a number k, find the largest sum of the subarray containing at least k numbers. 
  It is guaranteed that the size of array is at-least k.
*/

class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long sumTake, sumSlide=0, mx;
        for(int i=0; i<k; i++) sumSlide+=a[i];
        sumTake = mx = sumSlide;
        for(int i=k; i<n; i++)
        {
            sumSlide+=(a[i]-a[i-k]);
            sumTake=max(sumTake+a[i], sumSlide);
            mx=max(mx, sumTake);
        }
        return mx;
    }
};
