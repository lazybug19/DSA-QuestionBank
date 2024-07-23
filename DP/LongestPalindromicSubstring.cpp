class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==1) return s;
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
        int start=0, len=1;
        dp[n-1][n-1]=true;           
        for(int i=0; i<n-1; i++)
        {
            dp[i][i]=true;
            if(s[i]==s[i+1])
            {
                start=i;
                len=2;
                dp[i][i+1]=true;
            }
        }
        for(int l=3; l<=n; l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                int j=i+l-1;
                // expanding from center
                if(dp[i+1][j-1] && s[i]==s[j])
                {
                    dp[i][j]=true;
                    if(l>len)
                    {
                        start=i;
                        len=l;
                    }                   
                }
            }
        }
        string lps="";
        for(int i=start; i<start+len; i++)
            lps.push_back(s[i]);
        return lps;        
    }
};