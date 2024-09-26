class Solution {
public:
    bool isAnagram(unordered_map<char, int>& mp, unordered_map<char, int>& ms)
    {
        for(auto x: mp)
        {
            if(ms.find(x.first)==ms.end() || ms[x.first]!=x.second) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        for(char c: p) mp[c]++;

        unordered_map<char, int> ms;
        vector<int> res;
        int n=p.length(), m=s.length(), j=0;
        for(int i=0; i<m; i++)
        {
            if(i-j+1>n) 
            {
                ms[s[j]]--;
                if(ms[s[j]]==0) ms.erase(s[j]);
                j++;
            }
            ms[s[i]]++;
            if(i-j+1==n && isAnagram(mp, ms)) res.push_back(j);
        }
        return res;
    }
};
