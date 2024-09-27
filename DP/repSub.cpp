//Maximum length of repeated(common) subarray

//DP

class Solution {
private:
    int solve(vector<int>& nums1, vector<int>& nums2, int m, int n, int &maxlen, vector<vector<int>> &dp) {
        if(n == 0 || m == 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        int len = 0;
        if(nums1[m-1] == nums2[n-1])
            len = 1 + solve(nums1, nums2, m-1, n-1, maxlen, dp);
        maxlen = max(len, maxlen);
        solve(nums1, nums2, m-1, n, maxlen, dp); 
        solve(nums1, nums2, m, n-1, maxlen, dp);
        return dp[m][n] = len;
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int maxlen = 0;
        solve(nums1, nums2, m, n, maxlen, dp);
        return maxlen;
    }
};

//BS

bool check(int k, string &s1, string &s2){
    set<string>s;
    for(int i = 0; i <= s1.size()-k; ++i){
        s.insert(s1.substr(i,k));
    }
    for(int i = 0; i <= s2.size()-k; ++i){
        if( s.find(s2.substr(i,k)) != s.end() ) return true;
    }
    return false;
}


class Solution {
public:
    int findLength(vector<int>& n1 , vector<int>& n2) {
        string s1,s2;
        for(int i = 0; i < n1.size(); ++i){
            s1.push_back(n1[i] + '0');
        }
        for(int i = 0; i < n2.size(); ++i){
            s2.push_back(n2[i] + '0');
        }
        int l = -1, r = min(n1.size(),n2.size()) + 1;

        while(r - l > 1){
            int mid = (l+r)/2;
            if(check(mid, s1, s2)) l = mid;
            else r = mid;
        }

        return l;
    }
};
