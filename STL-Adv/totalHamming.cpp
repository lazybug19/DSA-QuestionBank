The total Hamming distance is constructed bit by bit in this approach.

Let's take a series of number: a1, a2, a3,..., an

Just think about all the Least Significant Bit (LSB) of a(k) (1 ≤ k ≤ n).

How many Hamming distance will they bring to the total?

If a pair of number has same LSB, the total distance will get 0.

If a pair of number has different LSB, the total distance will get 1.

For all number a1, a2, a3,..., a(n), if there are p numbers have 0 as LSB (put in set M), and q numbers have 1 for LSB (put in set N).

There are 2 situations:

Situation 1. If the 2 number in a pair both comes from M (or N), the total will get 0.

Situation 2. If the 1 number in a pair comes from M, the other comes from N, the total will get 1.

Since Situation 1 will add NOTHING to the total, we only need to think about Situation 2

How many pairs are there in Situation 2?

We choose 1 number from M (p possibilities), and 1 number from N (q possibilities).

The total possibilities is p × q = pq, which means

The total Hamming distance will get pq from LSB.
If we remove the LSB of all numbers (right logical shift), the same idea can be used again and again until all numbers becomes zero





class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return 0;
        int ans = 0;
        int *zeroOne = new int[2];
        while(true)
        {
            int zeroCount = 0;
            zeroOne[0] = 0;
            zeroOne[1] = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] == 0) zeroCount++;
                zeroOne[nums[i] % 2]++;
                nums[i] = nums[i] >> 1;
            }
            ans += zeroOne[0] * zeroOne[1];
            if(zeroCount == nums.size()) return ans;
        }
    }
};