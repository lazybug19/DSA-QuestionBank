// 3 Way Search: Given an array A[] consisting of only 0s, 1s, and 2s. 
// The task is to write a function that sorts the given array such that all 0s are followed by all 
// 1s that are followed by all 2s

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {2, 0, 2, 1, 1, 0};
    int low=0, mid=0, high=v.size()-1;
    while(mid<=high)
    {
        if(v[mid]==1) mid++;
        else if(v[mid]==0)
        {
            swap(v[mid], v[low]);
            mid++;
            low++;
        }
        else
        {
            swap(v[mid], v[high]);
            high--;
        }
    }
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    return 0;
}
