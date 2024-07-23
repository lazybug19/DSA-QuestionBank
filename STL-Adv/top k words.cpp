class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp; //AO of strings already
        vector<string> v;
        priority_queue<int> pq;
        for(int i=0; i<words.size(); i++) mp[words[i]]++;
        for(auto x:mp) pq.push(x.second);
        while (k>0) {
            int n = pq.top();
            pq.pop();
            for (auto x:mp) {
                if (n == x.second) {
                    v.push_back(x.first);
                    mp.erase(x.first);
                    k--;
                    break;
                }
            }
        }
        return v;
    }
};

