//pop out elements from nums1 and nums2 and assume it as an input stream
class Solution {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    void add(int x)
    {
        if(left.empty()||x<left.top()) left.push(x);
        else right.push(x);
        if(left.size()<right.size())
        {
            int temp=right.top();
            right.pop();
            left.push(temp);
        }
        if(left.size()>right.size()+1)
        {
            int temp=left.top();
            left.pop();
            right.push(temp);
        }
    }
    double median()
    {
        if(left.size()>right.size()) return left.top();
        return(left.top()+right.top())*0.5;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        for(int i:nums1)
            add(i);
        for(int i:nums2)
            add(i);
        return median();
    }
};