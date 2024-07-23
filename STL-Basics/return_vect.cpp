#include <bits/stdc++.h>
using namespace std;

vector<int> breakingRecords(vector<int> a)
{
    int max, min, mx = 0, mn = 0;
    if(a[1] != '\0')
    {
        if(a[0] > a[1]) 
        {
            max = a[0];
            min = a[1];
            mn++;
        }
        else if(a[0] < a[1]) 
        {
            max = a[1];
            min = a[0]; 
            mx++;
        }
        else
        {
            max = a[1];
            min = a[0]; 
        }
        for(int i = 1; i < a.size() - 1; i++)
        {
            if(a[i] > a[i + 1])
            {
                if(a[i] > max) 
                {
                    max = a[i];
                    mx++;
                }
                if(a[i + 1] < min) 
                {
                    min = a[i + 1];
                    mn++;
                }
            }
            else if(a[i] < a[i + 1])
            {
                if(a[i + 1] > max)
                {
                    max = a[i + 1];
                    mx++;
                }
                if(a[i] < min) 
                {
                    min = a[i];
                    mn++;
                }
            }
        }
    }
    vector<int> b;
        b.push_back(mx);
        b.push_back(mn);
    return b;
}

int main()
{
    int n, v;
    cin >> n;
    vector<int> a;
    for(int j = 0; j < n; j++)
    {
        cin >> v;
        a.push_back(v);
    }
    
    vector<int> b = breakingRecords(a);
    vector<int> :: iterator p;
    p = b.begin();
    cout << *p << " " << *(p + 1);
    
    return 0; 
}
