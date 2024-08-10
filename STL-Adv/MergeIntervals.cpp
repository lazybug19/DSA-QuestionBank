
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        res.push_back({arr[0][0], arr[0][1]});
        for(int i=1; i<n; i++){
            int j=res.size()-1;
            if(arr[i][0]<=res[j][1])
            {
                if(arr[i][1]>res[j][1])
                    res[j]={res[j][0], arr[i][1]};
            }
            else
            {
                res.push_back({arr[i][0], arr[i][1]});
            }
        }
        return res;
    }
};
