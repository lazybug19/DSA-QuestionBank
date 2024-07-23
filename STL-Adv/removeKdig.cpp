class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.length()) return "0";
        stack<char> s;
        for(char c: num)
        {
            while(!s.empty() && c<s.top() && k>0)
            {
                s.pop();
                k--;
            }
            if(s.empty() && c=='0') continue;
            s.push(c);
        }
        while(k!=0 && !s.empty())
        {
            s.pop();
            k--;
        }
        if(s.empty()) return "0";
        string res = "";
        while(!s.empty())
        {
            res+=s.top();
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};