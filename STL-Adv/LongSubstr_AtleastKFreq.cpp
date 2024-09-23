// Given a string s and an integer k, return the length of the longest substring of s such that the
// frequency of each character in this substring is greater than or equal to k.


// Divide n conquer algorithm : optimised method
class Solution {
public:
    int dnc(string s, int k, int start, int end)
    {
        if(end-start+1 < k) return 0;
        vector<int> freq(26, 0);
        for(int i=start; i<=end; i++) freq[s[i]-'a']++;
        for(int i=start; i<=end; i++)
        {
            if(freq[s[i]-'a'] < k) // this where we go to left or right to check as s[i] cannot contribute to final substring
            {
                int left=dnc(s, k, start, i-1);
                int right=dnc(s, k, i+1, end);
                return max(left, right);
            }
        }
        return end-start+1;
    }
    int longestSubstring(string s, int k) {
        return dnc(s, k, 0, s.length()-1);
    }
};
