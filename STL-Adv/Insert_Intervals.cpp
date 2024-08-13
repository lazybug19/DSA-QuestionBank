// Greedy Approach

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0, n=intervals.size();
        if(n==0) return {newInterval};
        vector<vector<int>> inserted;
        int start=newInterval[0], end=newInterval[1];
        while(i<n && intervals[i][1]<start)
        {
            inserted.push_back(intervals[i]);
            i++;
        }; 
        for(; i<n; i++)
        {
            if(end<intervals[i][0]) break;
            start=min(start, intervals[i][0]);
            end=max(end, intervals[i][1]);
        }
        inserted.push_back({start, end});
        for(; i<n; i++)
            inserted.push_back(intervals[i]);
        return inserted;
    }
};
