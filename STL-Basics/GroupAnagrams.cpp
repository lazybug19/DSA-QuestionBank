class Solution {
public:
    // all sorted anagrams result in same word
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for(string s: strs)
        {
            string tmp=s;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(s);
        }
        for(auto x: mp)
            res.push_back(x.second);
        return res;
    }
};
