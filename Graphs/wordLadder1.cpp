class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int steps=0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        while(!q.empty())
        {
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();

            if(word==endWord) return steps;

            for(int i=0; i<word.size(); i++)
            {
                char og = word[i];
                for(char c='a'; c<='z'; c++)
                {
                    word[i]=c;
                    if(st.find(word)!=st.end())
                    {
                        q.push({word, steps+1});
                        st.erase(word);
                    }
                }
                word[i] = og;
            }  
        }
        return 0;
    }
};