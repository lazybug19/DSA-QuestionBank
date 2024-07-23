//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    const static int mod = 1e9 + 7;
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int sum = 0;
        for (int x : arr)
            sum += x;
        if ((sum - d) % 2 != 0)
            return 0;
        int k = (sum + d) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        dp[0][0] = 1;
        for (int j = 1; j < k + 1; j++)
            dp[0][j] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; j < k + 1; j++)
            {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] % mod + dp[i - 1][j] % mod;
                else
                    dp[i][j] = dp[i - 1][j] % mod;
            }
        }
        return dp[n][k] % mod;
    }
};

// 1d solution for testcases where above solution gives TLE : target sum where +/- could be placed before each element for sum calculation
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int x : nums)
            sum += x;
        if ((sum - target) % 2 != 0)
            return 0;
        int k = (sum - target) / 2 + target;
        if (k < 0)
            return 0;

        vector<int> dp(k + 1, 0);
        dp[0] = 1;
        for (int i : nums)
        {
            for (int j = k; j >= i; j--)
            {
                dp[j] += dp[j - i];
            }
        }
        return dp[k];
    }
};