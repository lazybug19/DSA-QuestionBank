/* Equivalent to longest subarray with k (here k=2) distinct elements */

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int j=0, mx=0;
        for(int i=0; i<fruits.size(); i++)
        {
            mp[fruits[i]]++;
            if(mp.size()<=2) mx=max(mx, i-j+1);
            else
            {
                // erase only when after sliding window (inc j), freq of fruits[j] becomes 0
                mp[fruits[j]]--;
                if(mp[fruits[j]]==0) mp.erase(fruits[j]);
                j++;

                // only 57/93 tc pass with this logic
                /*
                while(mp.find(fruits[j]) == mp.end()) j++;
                mp.erase(fruits[j]);
                j++;
                */
            }
        }
        return mx;
    }
};
