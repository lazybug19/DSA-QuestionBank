class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int i = 0, xsum = 0;
        while(i < nums.size())
        {
            xsum ^= nums[i];
            i++;
        }
        int pos = 0, k = xsum;
        while(xsum > 0)
        {
            if(xsum & 1)
                break;
            pos++;
            xsum = xsum>>1; 
        }
        int j = 0, first = 0, mask = 1<<pos;
        while(j < nums.size())
        {
            if(nums[j] & mask)
                first ^= nums[j];
            j++;
        }
        int second = first^k;
        
        return {first, second};
    }
};