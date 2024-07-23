class Solution {
public:
    int minimumDifference(vector<int>& nums) { 
	    int total=0;
        for(int n: nums) total+=n;
        int n=nums.size()/2;
        vector<vector<int>> left(n+1), right(n+1);
        for(int m=0; m<(1<<n); m++)
        {
            int len=0;
            int lsum=0;
            int rsum=0;
            for(int i=0; i<n; i++)
            {
                if(m & (1<<i))
                {
                    len++;
                    lsum+=nums[i];
                    rsum+=nums[i+n];
                }
            }
            left[len].push_back(lsum);
            right[len].push_back(rsum);
        }
        for(int i=0; i<=n; i++) //subset length 0->N/2
            sort(right[i].begin(), right[i].end());
        int res=min(abs(total-2*right[n][0]), abs(total-2*left[n][0]));
        for(int i=1; i<n; i++) //not considering empty subsets
        {
            for(int x: left[i])
            {
                int idx=n-i;
                int sum=(total-2*x)/2;
                auto itr=lower_bound(right[idx].begin(), right[idx].end(), sum);
                if(itr!=right[idx].end())
                    res=min(res,abs(total-2*(x+*itr)));
            }
        }
        return res;
	} 
};