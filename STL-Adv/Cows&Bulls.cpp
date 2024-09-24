class Solution {
public:
    string getHint(string s, string g) {
        int n=s.length(), x=0, y=0;
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++) mp[s[i]]++;
        for(int i=0; i<n; i++)
        {
            if(s[i]==g[i])
            {
                x++;
                if(mp[g[i]]==1) mp.erase(g[i]);
                else mp[g[i]]--;
                g[i]='b';
            }
        }
        for(int i=0; i<n; i++)
        {
            if(g[i]!='b' && mp.find(g[i])!=mp.end())
            {
                y++;
                if(mp[g[i]]==1) mp.erase(g[i]);
                else mp[g[i]]--;
            }
        }
        return to_string(x)+"A"+to_string(y)+"B";
    }
};
