#include<bits/stdc++.h>
using namespace std;
vector<string> AllPossibleStrings(string s) {
	int n = s.length();
	vector<string>ans;
	for (int num = 1; num < (1 << n); num++) {//num=0 for empty string
		string sub = "";
		for (int i = 0; i < n; i++) {
			//check if the ith bit is set or not
			if (num & (1 << i)) {
				sub += s[i];
			}
		}
		ans.push_back(sub);
	}
	return ans;
}
int main()
{
	string s="abc";
	vector<string>ans = AllPossibleStrings(s);
	//print int all the subsequence.
	cout<<"All possible subsequences are "<<endl;
	for (auto it : ans) {
		cout << it << " ";
	}

}