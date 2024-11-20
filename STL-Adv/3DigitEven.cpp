// Solution 1:
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> st;
        int n=digits.size();
        for(int i=0; i<n; i++)
        {
            if(digits[i]==0) continue;
            for(int j=0; j<n; j++)
            {
                if(j==i) continue;
                for(int k=0; k<n; k++)
                {
                    if(k==i || k==j) continue;
                    if(digits[k]%2==0)
                    {
                        int num=100*digits[i]+10*digits[j]+digits[k];
                        st.insert(num);
                    }
                }
            }
        }
        return vector<int>(st.begin(), st.end());
    }
};

// Solution 2:
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> mp;
        vector<int> res;
        for(int d: digits) mp[d]++;
        for(int i=1; i<=9; i++)
        {
            for(int j=0; j<=9; j++)
            {
                for(int k=0; k<=8; k+=2)
                {
                    if(mp[i]>0) 
                    {
                        mp[i]--;
                        if(mp[j]>0)
                        {
                            mp[j]--;
                            if(mp[k]>0)
                            {
                                int num=100*i+10*j+k;
                                res.push_back(num);
                            }
                            mp[j]++;
                        }
                        mp[i]++;
                    } 
                }
            }
        }
        return res;
    }
};
