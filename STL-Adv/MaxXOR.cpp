/*if both a & b have a set bit take xor with 1 at that position.
if both a & b does not have a set bit take xor with 1 at that position.
if a is set but b is not set , then we will only take xor if a>b  -> we want to make both a & b closer to each other , in order to maximize multiplication .
if b is set but a is not set , then we will only take xor if b>a ,for the same reason in case 3
*/

// to maximise : (a^x) * (b^x) where x is in [0,2^n]

class Solution {
public:
    static const int mod=1e9+7;
    int maximumXorProduct(long long a, long long b, int n) {
        for(long long i=n-1; i>=0; i--)
        {
            //without LL, RE occurs
            if((a & 1LL<<i) && (b & 1LL<<i)) continue;
            else if((!(a & 1LL<<i) && !(b & 1LL<<i)) || ((a & 1LL<<i) && (a>b)) || ((b & 1LL<<i) && (b>a)))
            {
                a^=(1LL<<i);
                b^=(1LL<<i);
            }
        }
        a%=mod;
        b%=mod;
        return (a*b)%mod;
    }
};
