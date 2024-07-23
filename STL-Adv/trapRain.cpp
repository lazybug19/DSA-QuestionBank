//2 pointer
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left=0, right=n-1, max1=0, max2=0, sum=0;
        while(left<=right)
        {
            if(height[left]>=height[right])
            {
                if(height[right]>max1) max1=height[right];
                else sum+= max1-height[right];
                right--;
            }
            else
            {
                if(height[left]>max2) max2=height[left];
                else sum+= max2-height[left];
                left++;
            }
        }
    return sum;
    }
};














class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n), suffix(n);
        prefix[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], height[i]);
        }
        suffix[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], height[i]);
        }
        int sum = 0;
        for (int i = 1; i <= n-2; i++) {
            if(prefix[i]>height[i] && suffix[i]>height[i]) //may or may not
                sum += min(prefix[i], suffix[i]) - height[i];
        }
        return sum;
    }
};