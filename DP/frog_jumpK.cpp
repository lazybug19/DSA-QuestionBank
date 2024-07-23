/*Given a number of stairs and a frog, the frog wants to climb from the 0th 
stair to the (N-1)th stair. At a time the frog can climb k steps. A height[N] 
array is also given. Whenever the frog jumps from a stair i to stair j, the 
energy consumed in the jump is abs(height[i]- height[j]), where abs() means the 
absolute difference. We need to return the minimum energy that can be used by 
the frog to jump from stair 0 to stair N-1.*/


#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int>& height, vector<int>& dp, int k)
{
  if(i==0) return 0;
  if(dp[i]!=-1) return dp[i];
  int m = INT_MAX;
  for(int j=1; j<=k; j++)
  {
    if(i-j>=0){
        int jump = solve(i-j, height, dp, k) + abs(height[i-j]-height[i]);
        m = min(jump, m);
    }
  }
  return dp[i] = m;
}

int main() 
{
  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  int k=2;
  vector<int> dp(n,-1);
  cout<<solve(n-1,height,dp,k);
}