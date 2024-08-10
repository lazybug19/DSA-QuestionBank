/*
Given a set of n jobs where each jobi has a deadline and profit associated with it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
We earn the profit associated with a job if and only if the job is completed by its deadline.
Find the number of jobs done and the maximum profit.
Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. 
Deadline of the job is the time on or before which job needs to be completed to earn the profit.
*/


class Solution 
{
    public:
    static bool comp(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> res;
        sort(arr, arr+n, comp);
        int mx=INT_MIN, gain=0, cnt=0;
        for(int i=0; i<n; i++) mx=max(mx, arr[i].dead);
        vector<int> seq(mx, -1);
        for(int i=0; i<n; i++)
        {
            int idx=arr[i].dead-1;
            while(idx>=0)
            {
                if(seq[idx]==-1)
                {
                    seq[idx]=arr[i].profit;
                    gain+=arr[i].profit;
                    cnt++;
                    break;
                }
                idx--;
            }
        }
        res.push_back(cnt);
        res.push_back(gain);
        return res;
    } 
};
