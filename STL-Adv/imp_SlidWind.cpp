

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    v={2, 2, 1, 3, 4, 5, 5, 5, 4};
    int k=3, n=9, start=0, i=0, len, mx=INT_MIN; //k=no. of baskets, n=no. of trees
    unordered_map<int,int> mp;
    while(i<n)
    {
        mp[v[i]]++;
        while(mp.size()>k)
        {
            mp[v[start]]--;
            if(mp[v[start]] == 0)
                mp.erase(v[start]);
            start++;
        }
        len=i-start+1;
        //if(mp.size()<=k) -> at most k distinct
        //if(mp.size()==k) -> exqactly k
        mx=max(mx,len);
        i++;
    }
    cout << mx;
    return 0;
}