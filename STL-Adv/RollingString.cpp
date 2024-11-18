/*
Given a string s containing lowercase alphabets and an array roll where roll[i] represents rolling the first roll[i] 
characters in the string, the task is to apply every roll[i] on the string and return the final string. Rolling means 
increasing the ASCII value of the character; for example, rolling z would result in a, rolling b would result in c, etc.
*/

class Solution {
  public:
    // Function to find the new string obtained by rolling out characters.
    string findRollOut(string s, vector<int>& roll) {
        int n=s.length();
        vector<int> freq(n+1, 0);
        for(int r: roll)
        {
            freq[0]++;
            freq[r]--;
        }
        for(int i=1; i<=n; i++) freq[i]+=freq[i-1];
        for(int i=0; i<n; i++)
        {
            s[i]=(s[i]-'a' + freq[i])%26 + 'a';
        }
        return s;
    }
};
