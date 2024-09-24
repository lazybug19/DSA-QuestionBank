class Solution {
public:
    long long countSteps(long long curr, int n)
    {
        long long steps=0, first=curr, last=curr;
        while(first<=n)
        {
            steps+=(min((int)last, n)-first+1);
            first*=10; // lexicographically first
            last*=10;
            last+=9; // lexicographically last
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        long long curr=1;
        k--; // for counting curr as the 0th member or 0-based indexing
        while(k>0)
        {
            long long steps=countSteps(curr, n);
            if(steps<=k)
            {
                k-=steps; 
                curr++; // numerically next
            }
            else
            {
                k--; // for curr
                curr*=10; // lexicographically next
            }
        }
        return curr;
    }
};
