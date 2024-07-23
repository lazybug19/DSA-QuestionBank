class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while(n >= 5)
        {
            count += n/5;
            n=n/5;
        }
        return count;
        
    }
};


//TLE error if calculating factorial and then dividing by 10 continuosly like below:
class Solution {
public:
    unsigned int fact(unsigned int n)
    {
        if(n == 0 || n == 1) return 1;
        return n*fact(n-1);
    }
    int trailingZeroes(int n) {
        int count = 0, f = fact(n);
        while(f%10 == 0)
        {

            count++;
            f=f/10;
        }
        return count;
        
    }
};


