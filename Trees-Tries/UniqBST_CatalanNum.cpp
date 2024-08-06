// Structurally unique BSTs with n keys ranging from 1 to n = nth catalan number = nCr(2*n, n)/(n+1)
class Solution {
public:
    int numTrees(int n) {
        long long res = 1;
        for(int i=1; i<=n; i++)
            res=res*(n+i)/i;
        return (int)(res/(n+1));
    }
};
