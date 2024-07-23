#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, p;
    cin >> x;
    vector <int> a;
    for(int i = 0; i<x; i++)
    {
        cin >> p;
        a.push_back(p);
    }
    sort(a.begin(), a.end());    //AO arrangement

    int y = a[0], k = 0, m;
    while(k < x - 1)
    {
        for(int i = (y * a[k + 1]); i > 1; i--)
        {
            if(((i % y) == 0) && ((i % a[k + 1]) == 0))
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