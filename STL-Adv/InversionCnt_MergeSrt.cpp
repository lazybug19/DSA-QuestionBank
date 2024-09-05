// Given an array of integers. Find the Inversion Count in the array.  Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

// Application of Merge Sort algorithm

class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[], long long l, long long mid, long long r)
    {
        long long int cnt=0;
        long long lptr=l, rptr=mid+1;
        vector<long long> temp;
        while(lptr<=mid && rptr<=r)
        {
            if(arr[lptr]<=arr[rptr])
            {
                temp.push_back(arr[lptr]);
                lptr++;
            }
            else
            {
                temp.push_back(arr[rptr]);
                cnt+=(mid+1-lptr); //mid+1 being the size of the half array
                rptr++;
            }
        }
        while(lptr<=mid) 
        {
            temp.push_back(arr[lptr]);
            lptr++;
        }
        while(rptr<=r) 
        {
            temp.push_back(arr[rptr]);
            rptr++;
        }
        for(int i=l; i<=r; i++)
            arr[i]=temp[i-l];
            
        return cnt;
    }
    long long int mergeSort(long long arr[], int l, int r)
    {
        long long int cnt=0;
        if(l>=r) return cnt;
        int mid=l+(r-l)/2;
        cnt+=mergeSort(arr, l, mid);
        cnt+=mergeSort(arr, mid+1, r);
        cnt+=merge(arr, l, mid, r);
        return cnt;
    }
    long long int inversionCount(long long arr[], int n) {
        return mergeSort(arr, 0, n-1);
    }
};
