class Solution {
    string LexDistinctSub(string S)
    {
        stack<char> st;
        vector<int> vis(26, 0), freq(26, 0)
        
        for(int i=0; i<n; i++)
            freq[S[i]-'a']++;
            
        for(int i=0; i<n; i++)
        {
            char c=S[i];
            freq[c]--;
            if(vis[c]) continue;
            
            while(!st.empty() && st.top()<c && freq[st.top]>0)
            {
                vis[st.top()] = 0;
                st.pop();
            }
                
            st.push(c);
            vis[c]=1;
        }
        
        string res="";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        
        rteurn res;
    }
};
