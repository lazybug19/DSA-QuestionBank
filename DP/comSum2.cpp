//Solution1: combinationSum1:i->i+1 + hash set of vectors 
class Solution {
public:
    void find(int i, int target, vector<int>& candidates, vector<int>& v, vector<vector<int>>& res)
    {
        if(target==0)
        {
            res.push_back(v);
            return;
        }
        for(int j=i; j<candidates.size(); j++)
        {
            if(j>i && candidates[j]==candidates[j-1]) continue;
            if(candidates[j]>target) break;
            v.push_back(candidates[j]);
            find(j+1,target-candidates[j],candidates,v,res);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        find(0,target,candidates,v,res);
        return res;
    }
};