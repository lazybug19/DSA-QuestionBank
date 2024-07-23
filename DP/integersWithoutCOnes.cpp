class Solution {
public:
    int findIntegers(int n) {
        if(n==1) return 2;
        vector<int> dp(31, 0);
        dp[0]=1; // 0
        dp[1]=2; // 0 and 1
        for(int i=2; i<31; i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }

        bool prev_set=false;
        int count=0;
        for(int i=30; i>=0; i--)
        {
            if(n & 1<<i) 
            {
                count+=dp[i];
                if(prev_set) return count;
                prev_set=true;
            }
            else
                prev_set=false;          
        }
        return count+1;
    }
};

// MLE as 2d array is huge-ass
/*
    int findIntegers(int n) {
        if(n==1) return 2;
        int count=2;
        vector<vector<int>> bin(n+1, vector<int>(32, 0));
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<32; j++)
            {
                if(i & 1<<j)
                    bin[i][j]=1;
            }
        }
        for(int i=2; i<=n; i++)
        {
            int j;
            for(j=1; j<32; j++)
            {
                if(bin[i][j] && bin[i][j-1])
                    break;
            }
            if(j==32) count++;
        }
        return count;
    }
*/