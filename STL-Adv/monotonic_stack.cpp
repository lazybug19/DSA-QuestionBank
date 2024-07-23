class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    { 
        stack<int> S;
        // no need of ordered map i think
        unordered_map<int,int> nextGreater;
        for(int i=nums2.size()-1; i>=0; i--)
        {
            //(S.top()) becomes smaller than the current element.
            while(!S.empty() && S.top() <= nums2[i])
                S.pop();
            if(S.empty())
                nextGreater[nums2[i]] = -1;
            else
                nextGreater[nums2[i]] = S.top();
            S.push(nums2[i]);
        }

        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
            ans.push_back(nextGreater[nums1[i]]);
        return ans;
    }
};