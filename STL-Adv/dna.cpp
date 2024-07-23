class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> mp;
        vector<string> v;
        int i = 0;
        string r;
        for(int i = 0; i < 10; i++) r+=s[i];
        mp[r]++;
	  i = 10;
        while(i<s.size())
        {
            r.erase(r.begin());
            r.push_back(s[i]);
            mp[r]++;
            i++;
        }
        for(auto x: mp)
        {
            if(x.second > 1)
                v.push_back(x.first);
        }
        return v;
    }
};