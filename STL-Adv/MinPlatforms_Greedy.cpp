class Solution{
    public:
    int findPlatform(int start[], int end[], int n)
    {
        sort(start, start+n);
        sort(end, end+n);
        // it is fine to sort both arr and dep arrays separately as it keeps track of 
        // when a train arrives and when another train departs so not necessary
        // to keep track of departure time of a train only when its arrival is known
        
        
        int cnt=1, res=1, j=0, i=1;
        while(i<n && j<n)
        {
            if(start[i]<=end[j])
            {
                cnt++;
                i++;
            }
            else
            {
                cnt--;
                j++;
            }
            res=max(res, cnt);
        }
        return res;
    }
};
