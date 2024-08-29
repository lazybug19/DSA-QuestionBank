/*
Given an array and two numbers M and K. We need to find the max sum of sums of M subarrays of size K (non-overlapping) 
in the array. (Order of array remains unchanged). K is the size of subarrays and M is the count of subarray. It may be 
assumed that size of array is more than m*k. 
*/

// calculating presum of array. presum[i] is going to store prefix sum of subarray of size k beginning with arr[i]
void calculatePresumArray(int presum[], int arr[], int n, int k)
{ 
	for (int i=0; i<k; i++)
	  presum[0] += arr[i];

	// store sum of array index i to i+k in presum array at index i of it.
	for (int i = 1; i <= n - k; i++) 
	  presum[i] += presum[i-1] + arr[i+k-1] - arr[i-1];
}

// calculating maximum sum of m non overlapping array
int maxSumMnonOverlappingSubarray(int presum[], int m, int constraint, int k, int start)
{
	if (m == 0)	return 0;
	if (start > constraint - 1) return 0;
	// if including subarray of constraint k OR if excluding element and searching in all next possible subarrays
	return max(presum[start] + maxSumMnonOverlappingSubarray(presum, m - 1, constraint, k, start + k), maxSumMnonOverlappingSubarray(presum, m, constraint, k, start + 1);
}

// Driver code
int main()
{
	int presum[n + 1 - k] = { 0 }; // initialisation
	calculatePresumArray(presum, arr, n, k);

	// resulting presum array shouldn't go beyond idx=n+1-k
	cout << maxSumMnonOverlappingSubarray(presum, m, n + 1 - k, k, 0);
	return 0;
}
