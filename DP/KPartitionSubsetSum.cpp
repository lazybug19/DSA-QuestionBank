class Solution {
public:
    bool backTrack(vector<int> nums,vector<bool>& visited,int currsum,int x,int subsetsum,int k){
        if(k==0)return true;
        if(currsum>subsetsum)return false;
        if(currsum==subsetsum) return backTrack(nums,visited,0,0,subsetsum,k-1);
        for(int i=x;i<nums.size();i++)
        {
            if(visited[i])continue;
            visited[i] = true;
            if(backTrack(nums,visited,currsum+nums[i],i+1,subsetsum,k))return true;
            visited[i] = false;
            if(currsum==0) break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int n : nums)
            sum += n;
        if (sum % k) return false;
        int subsetsum = sum/k;
        vector<bool> v(nums.size(),false);
        return backTrack(nums,v,0,0,subsetsum,k);
    }
    
};