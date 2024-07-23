class Solution {
public:
    int i=0;
    vector<int> v;
    vector<vector<int>> res;
    set<vector<int>> s;
    void find(vector<int>& nums, int i)
    {
        if(i==nums.size())
        {
            s.insert(v);
            return;
        }
        v.push_back(nums[i]);
        find(nums,i+1);
        v.pop_back();
        find(nums,i+1);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());//imp: since set does element wise matching if sorted the order is always maintained
        find(nums, i);
        for(auto x: s)
            res.push_back(x);
        return res;
    }
};
