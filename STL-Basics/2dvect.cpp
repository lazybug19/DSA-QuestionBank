#include <bits/stdc++.h>
using namespace std;

int diagonalDifference(vector<vector<int>> a)
{
    int x = 0, y = 0, i = 0, k = 0, j = a.size() - 1;
    while(i < a.size())
    { 
        x = x + b[i++][i++];
    }
    while((k < a.size()) && (j >= 0))
    { 
        y = y + b[k++][j--];
    }
    int c = x - y;
    if(c > 0)
        cout << c;
    else cout << (-1) * c;
    return 0;
}

int main()
{
    int n, v;
    cin >> n;
    vector<vector<int>> a;
    for(int i = 0; i < n; i++)
    {
        vector<int> r;
        for(int j = 0; j < n; j++)
        {
            cin >> v;
            r.push_back(v);
            
        }
        a.push_back(r);
    }
    diagonalDifference(a);

    return 0; 
}

