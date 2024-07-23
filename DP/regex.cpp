class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(), m=p.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0]=true;
        char d='.', a='*'; // dot, asterisk
        for(int j=1; j<=m; j++)
        {
            if(p[j-1]==a)
                dp[0][j]=dp[0][j-2]; // considering zero occurences of prec. element
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                // char match || . matching any single char
                if(s[i-1]==p[j-1] || p[j-1]==d)
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]==a)
                {
                    // dp[i][j] : stores regex match result by comparing length i-1 with j-1
                    // dp[i-1][j] : 0 occurences : skip j-2 and compare i-2 with j-1
                    // dp[i][j-2] : >0 occurences : compare i-1 with j-3 (element before prec. element of *)
                    dp[i][j] = dp[i][j - 2];
                    if (p[j-2] == d || p[j-2] == s[i-1]) 
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};