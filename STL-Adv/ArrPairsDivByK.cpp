/*
 For two integers ( a ) and ( b ), their sum ( (a + b) ) is divisible by ( k ) if the sum of their remainders when 
 divided by ( k ) is either ( k ) or ( 0 ). This leads us to consider the remainders of each element when divided by 
 (k).
 */

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int> mp;
        for(int x: arr)
        {
            int a=(x%k+k)%k;
            if(a != 0)
            {
                if(mp.find(k-a)!=mp.end())
                {
                    mp[k-a]--;
                    if(mp[k-a]==0) mp.erase(k-a);
                }
                else mp[a]++;
            }
            else
            {
                if(mp.find(0)!=mp.end())
                {
                    mp[0]--;
                    if(mp[0]==0) mp.erase(0);
                }
            }
        }
        return mp.empty();
    }
};
