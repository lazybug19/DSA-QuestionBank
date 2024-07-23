#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& v, int f, int l)
{
    int x=f, y=l, p=f;
    while(x<y)
    {
        while(v[x] > v[p] && x < l) x++;
        while(v[y] < v[p] && y > f) y--;
        if(x<y) swap(v[x],v[y]);
    }
    swap(v[p],v[y]);
    return y;
}

void quickSort(vector<int>& v, int f, int l)
{
    if(f >= l) return;
    int pI = partition(v, f, l);
    if(f < pI-1)
        quickSort(v, f, pI-1);
    if(pI+1 < l)
        quickSort(v, pI+1, l);
}

int main()
{
    vector<int> v;
    v = {3, 4, 6, 1, 5, 2};
    int f = 0, l = 5;
    quickSort(v, f, l);
    cout << v[0] << v[1] << v[2] << v[3] << v[4] << v[5];
    return 0;
}