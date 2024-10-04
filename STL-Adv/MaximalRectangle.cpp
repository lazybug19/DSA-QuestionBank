/*
  Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and 
  return its area. (Modification of Largest Histogram)
*/

class Solution {
public:
    int largestRectangleArea(vector<int> heights) {
        int n=heights.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> s;
        for(int i=0; i<n; i++)
        {
            while(!s.empty() && heights[s.top()]>heights[i])
                s.pop();
            if(!s.empty()) left[i]=s.top();
            s.push(i);
        }

        s = stack<int>();
        for(int i=n-1; i>-1; i--)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();
            if(!s.empty()) right[i]=s.top();
            s.push(i);
        }        

        int mx=INT_MIN;
        for(int i=0; i<n; i++)
        {
            int area = (right[i]-left[i]-1)*heights[i];
            mx=max(area,mx);
        }
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int rows=matrix.size(), cols=matrix[0].size(), mxArea=0;
        vector<int> heights(cols, 0);
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                heights[j] = matrix[i][j]=='1' ? heights[j]+1 : 0;
            }
            mxArea=max(mxArea, largestRectangleArea(heights));
        }
        return mxArea;
    }
};
