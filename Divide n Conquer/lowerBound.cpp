#include <bist/stdc++.h>
using namespace std;

int first=0, last=v.size()-1, ans=v.size();
int lowerBound(int x, int first, int last)
{
	int mid=(first+last)/2;
	while(first<=last)
	{
		if(x<=v[mid])
		{
		  last=mid-1;	
		  ans=mid;
		}    
		if(x>v[mid])
		    first=mid+1;
		lowerBound(x,first,last);	
	}
	return v[ans];
}