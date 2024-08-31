/*
  Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats 
  k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat 
  any more bananas during this hour. Koko wants to finish eating all the bananas before the guards return. 
  Return the minimum integer k such that she can eat all the bananas within h hours.
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx=INT_MIN;
        for(int x: piles) mx=max(x, mx);
        int f=1, l=mx;
        while(f<l)
        {
            int mid=f+(l-f)/2, sum=0;
            for(int x: piles)
                sum+=ceil((double)x/(double)mid);
            if(sum<=h)
                l=mid;
            else
                f=mid+1;                            
        }
        return f;
    }
};
