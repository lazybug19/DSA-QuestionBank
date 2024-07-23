Majority Voting Algo: Find the majority element among the given elements that have more than N/ 2 occurrences
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {2, 2, 2, 3, 1, 3, 2, 1, 3, 3, 3};
    int count=0, element=v[0];
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]==element) count++;
        else
        {
            count--;
            if(count==0)
            {
                count=1;
                element=v[i];
            }
        }
    }
    
    int x=0;
    for(int i=0; i<v.size(); i++)
        if(v[i]==element) x++;
    if(x>v.size()/2) cout << element;
    else cout << -1;

    return 0;
}
