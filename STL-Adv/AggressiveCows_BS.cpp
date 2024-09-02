/*
You are given an array 'arr' of size 'n' which denotes the position of stalls. You are also given an integer 'k' 
which denotes the number of aggressive cows. You are given the task of assigning stalls to 'k' cows such that the 
minimum distance between any two of them is the maximum possible. Find the maximum possible minimum distance.
*/

class Solution {
public:
    bool findDistt(vector<int>& stalls, int k, int mid)
    {
        int cnt=1; // for stalls[0]
        int n=stalls.size(), last=stalls[0];
        for(int i=1; i<n; i++)
        {
            if(stalls[i]-last >= mid)
            {
                cnt++;
                last=stalls[i];
            }
            if(cnt>=k) return true;
        }
        return false;
    }
    int findStalls(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int mn=1, mx=stalls[stalls.size()-1]-stalls[0];

        while(mn<=mx)
        {
            int mid=mn+(mx-mn)/2; // max separation = mid
            if(findDist(stalls, k, mid)) 
                mn=mid+1;
            else 
                mx=mid-1;
        }
        return mx;
    }
};
