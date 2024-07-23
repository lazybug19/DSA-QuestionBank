//BRUTE_FORCE

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2)
            return false;
        if (k == 1)
            return true;
        int sum, i = 0, j, count = 0;
        while (i < nums.size() - 1) {
            j = i;
            sum = 0;
            count = 1;
            while (j < nums.size()) {
                sum += nums[j];
                if ((sum % k == 0) && (count > 1))
                    return true;
                count++;
                j++;
            }
            i++;
        }
        return false;
    }
};


//PREFIX_SUM
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0]=-1;
        int sum=0;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            if(mp.find(rem)==mp.end())
                mp[rem]=i;
            else if(i-mp[rem]>1)
                return true;
        }
        return false;
    }
};