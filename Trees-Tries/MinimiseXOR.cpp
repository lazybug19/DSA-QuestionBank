class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<32> b(num2);
        int req=b.count(), res=0;
        for(int i=31; i>=0 && req; i--)
        {
            if((num1>>i)&1)
            {
                res|=(1<<i);
                req--;
            }
        }
        for(int i=0; i<32 && req; i++)
        {
            if(!((res>>i)&1))
            {
                res|=(1<<i);
                req--;
            }
        }
        return res;
    }
};

