class NumArray {
private: 
    vector<int> nums;
    vector<int> seg;
    void buildST(vector<int>& nums, size_t root, size_t left, size_t right)
    {
        // leaf node
        if(left==right) seg[root]=nums[left];
        else
        {
            size_t mid=left+(right-left)/2;
            buildST(nums, 2*root, left, mid);
            buildST(nums, 2*root+1, mid+1, right);
            seg[root] = seg[2*root] + seg[2*root+1]; //1-based indexing
        }
    }

    int queryST(size_t root, size_t left, size_t right, size_t qLeft, size_t qRight)
    {
        if(qRight<left || qLeft>right) return 0;
        else if(qRight>=right && qLeft<=left) return seg[root];
        else
        {
            size_t mid=left+(right-left)/2;
            return queryST(2*root, left, mid, qLeft, qRight) + queryST(2*root + 1, mid + 1, right, qLeft, qRight);
        }
        return 0;
    }

    void updateST(size_t index, int val, size_t left, size_t right, size_t root)
    {
        if(left==right) // leaf node
        {
            nums[left]=val;
            seg[root]=val;
        }
        else
        {
            size_t mid=left+(right-left)/2;
            if(left<=index && index<=mid)
                updateST(index, val, left, mid, 2*root);
            else
                updateST(index, val, mid+1, right, 2*root+1);
            seg[root] = seg[2*root] + seg[2*root + 1];
        }
    }
public:
    NumArray(vector<int>& nums) {
        this->nums=nums;
        seg.resize(4*nums.size(), 0);
        buildST(nums, 1, 0, nums.size()-1); // build segment tree
    }
    
    void update(int index, int val) {
        updateST(index, val, 0, nums.size()-1, 1);
    }
    
    int sumRange(int left, int right) {
        return queryST(1, 0, nums.size()-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
