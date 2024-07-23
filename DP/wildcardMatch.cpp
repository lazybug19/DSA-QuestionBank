class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(), m=p.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0]=true;
        char q='?', a='*'; // dot, asterisk
        for(int j=1; j<=m; j++)
        {
            int i=0;
            while(i<j && p[i]==a)
                i++;
            if(i==j)
                dp[0][j]=true;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                // char match OR ? matching any single char
                if(s[i-1]==p[j-1] || p[j-1]==q)
                    dp[i][j]=dp[i-1][j-1];
                else
                {
                    // dp[i-1][j] : call for 0 occurrences as we don't need more char match OR
                    // dp[i][j-1] : call for * to represent s[i-1] char
                    if(p[j-1]==a)
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    else
                        dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};