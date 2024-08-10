#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& v, int first, int mid, int last)
{
    int f = first, m = mid+1;
    vector<int> temp;
    while(f <= mid && m <= last)
    {
        if(v[f] <= v[m]) // >= for ascending
        {
            temp.push_back(v[m]);
            m++;
        }
        else 
        {
            temp.push_back(v[f]);
            f++;
        }
    }
    while(f <= mid)
    {
        temp.push_back(v[f]);
        f++;
    }
    while(m <= last)
    {
        temp.push_back(v[m]);
        m++;
    }
    for(int i = first; i<=last; i++)
        v[i] = temp[i-first];
}
void mergeSort(vector<int>& v, int first, int last)
{
    if(first >= last) return;
    int mid = (first+last)/2;
    mergeSort(v, first, mid);
    mergeSort(v, mid+1, last);
    merge(v, first, mid, last);
}
int main()
{
   vector<int> v = {1, 2, 3, 4, 5, 6}; 
   mergeSort(v, 0, 5);
   
   cout << v[0] << v[1] << v[2] << v[3] << v[4] << v[5];
   return 0;
}
