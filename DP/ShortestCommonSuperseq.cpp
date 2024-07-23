class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(), m=str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(str1[i-1]==str2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int i=n, j=m;
		string sub="";
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                sub.push_back(str1[i-1]);
                //move diagonally
                i--;
                j--;
            }
            else
            {
                //moving either side
                if(dp[i][j-1]<dp[i-1][j]) 
                {
                    sub.push_back(str1[i-1]);
                    i--;
                }
                else 
                {
                    sub.push_back(str2[j-1]);
                    j--;                    
                }
            }
        }
        while(i>0) 
        {
            sub.push_back(str1[i-1]);
            i--;
        }
        while(j>0) 
        {  
            sub.push_back(str2[j-1]);
            j--;
        }
        reverse(sub.begin(), sub.end());
        return sub;
    }
};