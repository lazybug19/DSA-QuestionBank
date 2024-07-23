class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const long long mod = 1e9 + 7;
        int n=arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> s;
        for(int i=0; i<n; i++)
        {
            while(!s.empty() && arr[s.top()]>arr[i])
                s.pop();
            if(!s.empty())
                left[i] = s.top();
            s.push(i);
        }
        s = stack<int>();
        for(int i=n-1; i>-1; i--)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
                s.pop();
            if(!s.empty())
                right[i] = s.top();
            s.push(i);
        }
        long long sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=((i-left[i])%mod)*((right[i]-i)%mod)*arr[i]%mod;
            sum%=mod;
        }

        return sum;    
    }
};