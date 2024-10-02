/*
  Given an array of length ‘N’, where the array represents the boards and each element of the given array represents the length of each board. 
  Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. You are supposed to return 
  the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections 
  of boards.
*/

class Solution {
public:
    int findPainters(vector<int>& boards, int mid)
    {
        int sum=0, cnt=0;
        for(int i=0; i<n; i++)
        {
            sum+=boards[i];
            if(sum>mid)
            {
                cnt++;
                sum=boards[i];
            }
        }
        cnt++;
        return cnt;
    }
    int findStalls(vector<int>& boards, int n, int m) {
        sort(boards.begin(), boards.end());
        int mn=boards[n-1], mx=0;
        for(int x: boards) mx+=x;

        while(mn<=mx)
        {
            int mid=mn+(mx-mn)/2; // max boards allocated = mid
            if(findPainters(pages, mid) > m) 
                mn=mid+1;
            else 
                mx=mid-1;
        }
        return mn;
    }
};
