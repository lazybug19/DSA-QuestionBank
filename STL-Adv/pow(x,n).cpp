//recursive (stack overflow for max edge cases)
class Solution {
public:
    double power(long long i, double x, int n)
    {
        if(i++<abs(n)) return x*power(i,x,n);
        return 1;
    }
    double myPow(double x, int n) {
        long long i=0;
        if(n>0) return power(i,x,n);
        return 1/power(i,x,n);
    }
};

//binary exponentiation
class Solution {
public:
    double power(double x, int n, double ans)
    {
        if(n==0) return 1;
        ans*=power(x,n/2,ans);
        ans*=ans;
        if(n%2!=0)
            return ans*x;
        return ans;
    }
    double myPow(double x, int n) {
        double ans=1.0;
        if(n<0) 
        {
            n=abs(n);
            return 1/power(x,n,ans);
        }
        return power(x,n,ans);       
    }
};