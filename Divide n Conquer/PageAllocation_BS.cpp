/*
Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. 
There are a ‘m’ number of students, and the task is to allocate all the books to the students such that:
  Each student gets at least one book. Each book should be allocated to only one student. Book allocation 
  should be in a contiguous manner. 
Maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1
*/

class Solution {
public:
    int findStudents(vector<int>& pages, int mid)
    {
        int sum=0, cnt=0;
        for(int i=0; i<n; i++)
        {
            sum+=pages[i];
            if(sum>mid)
            {
                cnt++;
                sum=pages[i];
            }
        }
        cnt++;
        return cnt;
    }
    int findStalls(vector<int>& pages, int n, int m) {
        if(m>n) return -1; // if students are more than books
        sort(pages.begin(), pages.end());
        int mn=pages[n-1], mx=0;
        for(int x: pages) mx+=x;

        while(mn<=mx)
        {
            int mid=mn+(mx-mn)/2; // max pages allocated = mid
            if(findStudents(pages, mid) > m) 
                mn=mid+1;
            else 
                mx=mid-1;
        }
        return mx;
    }
};
