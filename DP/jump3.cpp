class Solution {
public:
    bool solve(vector<int>& vis, vector<int>& arr, int i)
    {
        if(i<0 || i>arr.size()-1 || vis[i]) return false;
        if(arr[i]==0) return true;
        if(!vis[i]) vis[i]=1;
        
        return (solve(vis, arr, i+arr[i]) || solve(vis, arr, i-arr[i]));
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size()+1, 0);
        return solve(vis, arr, start);
    }
};
