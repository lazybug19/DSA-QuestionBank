#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    v = {3, 4, 5, 1, 2};
    for(int j = v.size()-1; j > 0; j--)
    {
        for(int i = 0; i < j; i++)
        {
            if(v[i] > v[i+1]) //< for descending
                swap(v[i], v[i+1]);
        }
    }
    cout << v[0] << v[1] << v[2] << v[3] << v[4];
    
    return 0;
}
