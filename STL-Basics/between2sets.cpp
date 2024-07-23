#include <bits/stdc++.h>
using namespace std;

void getTotalX(vector<int> f, vector<int> s)
{
    int count = 0;
    for(int x = 1; x <= 100; x++)
    {
        int k = 1;
        for(int i = 0; i < f.size(); i++) 
            if(x%f[i]!=0) k = 0;
        for(int i = 0; i < s.size(); i++) 
            if(s[i]%x!=0) k = 0; 
        if(k == 1) 
            count++;
    }
    cout << count;
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
       cin >> a[i];
    }
    
    vector<int> b(m);
    for(int i = 0; i < m; i++)
    {
       cin >> b[i];
    }
    
    getTotalX(a, b);
    
    return 0;
}