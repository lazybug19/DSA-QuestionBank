// an array having elements from 1 to n has 1 element repeating and 1 element missing
// find both elements in format : {duplicate, missing}

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int og=0, ac=0, m=0, d=0;
        for(int x: nums) ac^=x;
        for(int i=1; i<=nums.size(); i++) og^=i;

        int fin=og^ac, idx=(fin & -fin);
        int xorSet=0, xorNSet=0;
        for(int i=1; i<=nums.size(); i++)
        {
            if(i&idx) xorSet^=i;
            else xorNSet^=i;
        }
        for(int x: nums)
        {
            if(x&idx) xorSet^=x;
            else xorNSet^=x;
        }
        for(int x: nums)
        {
            if(x==xorSet) return {xorSet, xorNSet};
        }
        return {xorNSet, xorSet};
    }
};
