#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;// = {1, 3, 7, 1, 9};
    int k, start=0, end=0, sum=v[start];//k=10
    while(start<v.size() && end<v.size())
    {
        if(sum>k)
        {
            sum-=v[start];
            start++;
        }
        else
        {
            if(sum == k)
            {
                for(int i=start; i<end+1; i++)
                cout << v[i] << " ";
                cout << endl; //{3,7} {1,9}
            }
            end++;
            if(end<v.size())
                sum+=v[end];
        }
    }
}
