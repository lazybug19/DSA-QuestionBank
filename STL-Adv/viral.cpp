#include <bits/stdc++.h>
using namespace std;

void viralAdvertising(int n)
{
    int l, s = 5, sum = 0;
    for(int i = 1; i <= n; i++)
    {
        l = s/2;
        sum = sum + l;
        s = l*3;
    }
    
    cout << sum;
}

int main()
{
    int n;
    cin >> n;
    viralAdvertising(n);
    
    return 0;
}