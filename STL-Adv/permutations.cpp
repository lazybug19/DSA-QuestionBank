#include <bits/stdc++.h>
using namespace std;

void permute(string& v, int l, int r)
{
    if(l==r)
        cout << v << endl;
    else
    {
        for(int i=l; i<=r; i++)
        {
            swap(v[i],v[l]);
            permute(v,l+1,r);
            swap(v[i],v[l]);
        }
    }
}
int main()
{
    string v;
    v="1234";
    permute(v, 0, v.size()-1);
    return 0;
}