string abbreviation(string a, string b) {
    int n=a.length(), m=b.length();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1));
    dp[0][0] = true; //a, b empty
    for(int i=1; i<n+1; i++)
        if(isupper(a[i-1])) dp[i][0]=false;
    for(int j=1; j<m+1; j++) //char from b traverses a not vice-versa
    {
        for(int i=j; i<n+1; i++)
        {
            if(isupper(a[i-1]))
                dp[i][j]=dp[i-1][j] && toupper(a[i-1])==b[j-1];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][m] ? "YES" : "NO";
}