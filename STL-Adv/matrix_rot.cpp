class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target) return true; //0 deg
        int n=mat.size(), deg=3; //deg=3 (90, 180, 270)
        while(deg>0)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=i+1; j<n; j++)
                    swap(mat[i][j], mat[j][i]);
            }
            for(int i=0; i<n; i++)
            {
                int high=n-1, low=0;
                while(low<high)
                {
                    swap(mat[i][low], mat[i][high]);
                    high--;
                    low++;
                }
            }
            if(mat==target) return true;
            deg--;
        }
        return false;
    }
};