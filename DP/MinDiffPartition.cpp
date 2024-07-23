class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum=0;
	    for(int i=0; i<n; i++) sum+=arr[i];
	    int s=sum/2;
	    vector<vector<bool>> dp(n+1, vector<bool>(s+1));
	    dp[0][0]=true;
	    for(int j=1; j<s+1; j++)
	        dp[0][j]=false;
	    for(int i=1; i<n+1; i++)
	    {
	        for(int j=0; j<s+1; j++)
	        { 
	            dp[i][0]=true;
	            if(arr[i-1]<=j) 
	                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
	            else
	                dp[i][j] = dp[i-1][j];
	        }
	    }
	    int mn=INT_MAX;
	    for(int j=0; j<s+1; j++)
	    {
	        if(dp[n][j]) mn=min(mn, (sum-2*j));
	    }
	    return mn;
	} 
};