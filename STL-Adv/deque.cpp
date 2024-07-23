#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, v, max;
    deque<int> m;
    deque<int> m1;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n >> k;
        for(int j = 0; j < n; j++)
        {
            cin >> v;
            m.push_back(v);
        }
        int max = v.front();
        while(int j < n)
        {
            for(int l = 1; l < k; l++)
            {
                if(max <= v[l])
                max = v[l];
            }
            m1.push_back(max);
            j++;
        }
        cout << m1;
        
    }
    
    return 0;
}