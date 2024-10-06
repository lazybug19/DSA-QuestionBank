/*
If index = i, and no. of columns in the matrix = m, the index i corresponds to the cell with
row = i / m and col = i % m. More formally, the cell is (i / m, i % m)(0-based indexing).
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        long long start=0, end=(n*m)-1;
        while(start<=end)
        {
            long long mid=start+(end-start)/2;
            long long row=mid/m, col=mid%m;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) end=mid-1;
            else start=mid+1;
        }
        return false;
    }
};
