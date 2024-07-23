class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int>s1,s2;
        int n = nums.size();

        vector<int>rightMin(n,n);
        vector<int>rightMax(n,n);
        vector<int>leftMin(n,-1);
        vector<int>leftMax(n,-1);

        for(int i=0;i<n;i++){
            while(!s1.empty() && nums[s1.top()]>nums[i]){
                s1.pop();
            }
            while(!s2.empty() && nums[s2.top()]<nums[i]){
                s2.pop();
            }

            if(!s1.empty()) leftMin[i] = s1.top();
            if(!s2.empty()) leftMax[i] = s2.top();
            s1.push(i);
            s2.push(i);
        }

        s1 = stack<int>();
        s2 = stack<int>();

        for(int i=n-1;i>=0;i--){
            while(!s1.empty() && nums[s1.top()]>=nums[i]){
                s1.pop();
            }
            while(!s2.empty() && nums[s2.top()]<=nums[i]){
                s2.pop();
            }

            if(!s1.empty()) rightMin[i] = s1.top();
            if(!s2.empty()) rightMax[i] = s2.top();
            s1.push(i);
            s2.push(i);
        }

        long long sum = 0;
        for(int i=0;i<n;i++){
            long long a =  i - leftMin[i];
            long long b = rightMin[i] - i;
            long long c = i - leftMax[i];
            long long d = rightMax[i] - i;
            sum+=(c*d-a*b)*nums[i];
        }
        return sum;

    }
};