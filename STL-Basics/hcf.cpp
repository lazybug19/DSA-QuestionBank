#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, p, z = 1, l;
    cin >> x;
    vector <int> a;
    for(int i = 0; i<x; i++)
    {
        cin >> p;
        a.push_back(p);
    }
    sort(a.begin(), a.end());    //AO arrangement

    int y = a[0], k = 0, m;
    while(k < 2)
    {
        for(int i = 1; i <= y; i++)
        {
            if(((y % i) == 0) && ((a[k + 1] % i) == 0))
            {
                m = i;
            }
        }
        k++;
        y = m;
    }
     
    cout << m;
    
    return 0;

}