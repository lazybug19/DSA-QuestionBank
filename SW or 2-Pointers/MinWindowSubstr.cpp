// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring of s such that every character in t (including duplicates) is included in the window. 
// If there is no such substring, return the empty string "".

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.length()<t.length()) return "";
        int i=0, j=0, mn=INT_MAX, n=s.length(), start=0;
        unordered_map<char, int> mt;
        unordered_map<char, int> ms;
        int reqCnt=t.length(); //count of characters required
        for(char c: t) mt[c]++;
        while(i<n)
        {
            ms[s[i]]++;
            if(ms[s[i]]<=mt[s[i]]) reqCnt--;
            while(reqCnt==0)
            {
                if(mn>i-j+1)
                {
                    mn=i-j+1;
                    start=j;
                }
                ms[s[j]]--;
                if(ms[s[j]]<mt[s[j]]) reqCnt++;
                j++;
            }
            i++;
        }
        return mn==INT_MAX ? "" : s.substr(start, mn);
    }
};
