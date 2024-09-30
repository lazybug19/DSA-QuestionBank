/*
  Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, 
  otherwise, return false.
*/

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n=s.length(), m=goal.length();
        if(n!=m) return false;
        if(s==goal)
        {
            unordered_set<char> st(s.begin(), s.end());
            return st.size()<n;
        }

        int prev=-1, cnt=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]!=goal[i])
            {
                if(prev!=-1) swap(s[i], s[prev]);
                prev=i; 
                cnt++;               
            }
        }
        if(s==goal && cnt==2) return true;
        return false;
    }
};

/*
  Return true if it is possible to make both strings equal by performing at most one string swap on exactly one 
  of the strings. Otherwise, return false. Given: strings are of equal length
*/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int n=s1.length();

        int prev=-1, cnt=0;
        for(int i=0; i<n; i++)
        {
            if(s1[i]!=s2[i])
            {
                if(prev!=-1) swap(s1[i], s1[prev]);
                prev=i; 
                cnt++;               
            }
        }
        if(s1==s2 && cnt==2) return true;
        return false;
    }
};
