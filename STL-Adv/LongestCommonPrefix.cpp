class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string small, large, s;
        sort(strs.begin(), strs.end());
        small=strs[0];
        large=strs[strs.size()-1];
        for(int i=0; i<small.size(); i++)
        {
            if(small[i]!=large[i]) break;
            s+=small[i];
        }
        return s;
    }
};
