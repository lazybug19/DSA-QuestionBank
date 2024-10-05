/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of 
the ith line are (i, 0) and (i, height[i]). Find two lines that together with the x-axis form a container, such that 
the container contains the most water. Return the maximum amount of water a container can store.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1, mx=0, l=0, r=0, b, area;
        while(left<right)
        {
            b=right-left;
            if(height[left]<height[right])
            {
                if(height[left]>l)
                {
                    l=height[left];
                    area=l*b;
                    left++;
                }
                else
                {
                    left++;
                    continue;
                } 
                           
            }
            else
            {
                if(height[right]>r)
                {
                    r=height[right];
                    area=r*b;
                    right--;
                }
                else
                {
                    right--;
                    continue; 
                }
            }
            mx=max(area,mx);
        }
        return mx;        
    }
};
