/*Given an array of ‘N’  positive integers, we need to return the maximum sum 
of the subsequence such that no two elements of the subsequence are adjacent 
elements in the array.*/

#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int>& arr, vector<int>& dp)
{
  if(dp[i]!=-1) return dp[i];
  if(i==0) return arr[i]; //if(i==n-1) return arr[i];
  if(i<0) return 0; //if(i>n) return 0;

  int sum1 = arr[i] + solve(i-2, arr, dp);//i+2
  int sum2 = 0 + solve(i-1, arr, dp);//i+1
  int maxSum = max(sum1, sum2);
  
  return dp[i] = maxSum;
}

int main() 
{
  vector<int> array{2,1,4,9};
  int n=array.size();
  vector<int> dp(n+1,-1);
  cout<<solve(n,array,dp); //n-1->0
}