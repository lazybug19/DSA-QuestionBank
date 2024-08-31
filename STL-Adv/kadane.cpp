/*
    KADANE'S ALGO: Given an array arr[] of size N. The task is to find the sum of the contiguous subarray within an 
    arr[] with the largest sum.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 4, 9, -1, -2, 0};
    int sum=0, max=INT_MIN;
    for(int i=0; i<6; i++)
    {
        sum+=v[i];
        if(sum > max) {
            max = sum;
        }
        if (sum<0) {
            sum=0;
        }
    }
    cout<<max;
    
    return 0;
}
