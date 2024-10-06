/*
You are given an array of integers start and an integer d, representing n intervals [start[i], start[i] + d].
You are asked to choose n integers where the ith integer must belong to the ith interval. The score of the chosen 
integers is defined as the minimum absolute difference between any two integers that have been chosen.
Return the maximum possible score of the chosen integers.
*/

class Solution {
public:
    bool findCount(vector<int>& start, int d, long long mid)
    {
        int prev=start[0], n=start.size();
        for(int i=1; i<n; i++)
        {
            long long curr=max((long long)(prev + mid), (long long)start[i]);// atleast mid away from prev
            if(curr>start[i]+d) return false;
            prev=curr;
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        long long begin=1, end=start[start.size()-1]+d-start[0];
        while(begin<=end)
        {
            long long mid=begin+(end-begin)/2;
            if(findCount(start, d, mid)) begin=mid+1;
            else end=mid-1;
        }
        return end; // min diff maxmised
    }
};
