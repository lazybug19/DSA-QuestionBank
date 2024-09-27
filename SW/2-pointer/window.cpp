// Sliding Window: Given an array of integers of size ‘n’, Our aim is to calculate the maximum sum of ‘k’ consecutive elements in the array.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 4, 9, -1, -2, 0};
    int k = 2, sum = 0, max = INT_MIN;
    for (int i = 0; i < k; i++)
        sum += v[i];
    for (int i = k; i < v.size(); i++)
    {
        sum += v[i] - v[i - k];
        if (sum > max)
            max = sum;
    }
    cout << max;

    return 0;
}