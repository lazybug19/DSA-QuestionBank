class Solution
{
    public:
    static bool comp(pair<int, int>& a, pair<int, int>& b)
    {
        if(a.second<b.first)
            return a.second<b.first;
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> times;
        for(int i=0; i<n; i++)
            times.push_back({start[i], end[i]});
        sort(times.begin(), times.end(), comp);
        int mxCnt=1, last=times[0].second;
        for(int i=1; i<n; i++)
        {
            if(times[i].first>last)
            {
                mxCnt++;
                last=times[i].second;
            }
        }
        return mxCnt;
    }
};
