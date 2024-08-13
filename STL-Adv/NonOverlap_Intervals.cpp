class Solution {
public:
    static bool comp(vector<int>& v1, vector<int>& v2)
    {
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size(), cnt=0, j=0;
        sort(intervals.begin(), intervals.end(), comp);
        for(int i=1; i<n; i++)
        {
            if(intervals[i][0]>=intervals[j][1])
            {
                cnt++;
                j=i;
            }
        }
        return n-cnt-1;
    }
};
