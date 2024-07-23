class Solution {
public:
    void find(int i, int target, vector<int>& arr, vector<int>& v, vector<vector<int>>& res)
    {
        if(i==arr.size())
        {
            if(target==0)
                res.push_back(v);
            return;
        }
        if(arr[i]<=target)
        {
            v.push_back(arr[i]);
            find(i,target-arr[i],arr,v,res);
            v.pop_back();
        }
        find(i+1,target,arr,v,res);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
        vector<int> v;
        find(0,target,arr,v,res);
        return res;        
    }
};