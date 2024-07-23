#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    v = {3, 4, 5, 1, 2};
    int m; 
    for(int j = 0; j < v.size()-1; j++)
    {
        m = j;
        for(int i = j+1; i < v.size(); i++)
        {
            if(v[m] < v[i]) //> for ascending
                m = i;
        }
        swap(v[j], v[m]);
    }
    cout << v[0] << v[1] << v[2] << v[3] << v[4];
    
    return 0;
}
