class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int xor1=0, xor2=0, n=grid.size();
        for(int i=1; i<n*n; i++)
            xor1=xor1^i;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                xor2=xor2^grid[i][j];
        }

        int fxor=xor1^xor2;

        //find first set bit
        int pos;
        for(int i=0; i<32; i++)
        {
            if(fxor & (1<<i))
            {
                pos=i;
                break;
            }
        }
        
        int a=0, b=0;
        for(int i=1; i<n*n; i++)
        {
            if(i & (1<<pos))
                a^=i;
            else
                b^=i;

        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] & (1<<pos))
                    a^=grid[i][j];
                else
                    b^=grid[i][j];
            }
        }
        vector<int> v;
        b=fxor^a;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==a)
                    return{a, b};
            }
        }
        return{b, a};
    }
};