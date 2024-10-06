/*
  Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. 
  If such an index does not exist, return -1.
*/

class Solution {
public:
    int findPeak(MountainArray &mountainArr, int n) {
        if(n==1 || mountainArr.get(0)>mountainArr.get(1)) return 0;
        if(mountainArr.get(n-1)>mountainArr.get(n-2)) return n-1;
        int f=1,l=n-2,mid;
        while(f<=l)
        {
            mid=(f+l)/2;
            if(mountainArr.get(mid)>mountainArr.get(mid-1) && mountainArr.get(mid)>mountainArr.get(mid+1)) 
                return mid;
            if(mountainArr.get(mid)>=mountainArr.get(mid-1))
                f=mid+1;
            else 
                l=mid-1;
        }
        return -1;        
    }
    int bs(int start, int end, MountainArray &mountainArr, int target, int flag)
    {
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(mountainArr.get(mid)==target) return mid;
            else if(mountainArr.get(mid)>target) 
            {
                if(flag==1) end=mid-1; // inc range
                else start=mid+1; // dec range
            }
            else 
            {
                if(flag==1) start=mid+1; // inc range
                else end=mid-1; // dec range
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length(), peakIdx=findPeak(mountainArr, n);
        if(mountainArr.get(peakIdx)==target) return peakIdx;
        if(mountainArr.get(peakIdx)<target) return -1;

        int req=bs(0, peakIdx-1, mountainArr, target, 1);
        return req==-1 ? bs(peakIdx+1, n-1,  mountainArr, target, 0) : req;
    }
};                                           
