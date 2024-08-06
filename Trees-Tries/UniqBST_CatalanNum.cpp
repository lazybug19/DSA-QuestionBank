class Solution {
public:
    int numTrees(int n) {
        long long res = 1;
        for(int i=1; i<=n; i++)
            res=res*(n+i)/i;
        return (int)(res/(n+1));
    }
};
