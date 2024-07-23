#include <bits/stdc++.h>
using namespace std;

void migratoryBirds(vector<int> b)
{
    vector<pair <int, int>> frequency;
    for(int i = 0; i < b.size(); i++)
    {
        int count = 0;
        int n = 0;
        for(int j = i; j < b.size(); j++)
        {
            if(b[j] == b[i])
            {
                count++;
                n++;
            }
            else
            {
                frequency.push_back(make_pair(count, b[i]));
                i = i + n - 1;
                break;
            }
        }
    }
    
    sort(frequency.begin(), frequency.end());
    int s = frequency.size();
    int max_count = frequency[s - 1].first;
    int min_value = frequency[s - 1].second;
    for(int i = s - 2; i > 0; i--)
    {
        if(frequency[i].first == max_count)
        {
            if(frequency[i].second < min_value) 
               min_value = frequency[i].second;
        }
        else
            break;
    }

    cout << min_value; 
}

int main()
{
    int n, v;
    cin >> n;
    vector<int> birds;
    for(int i = 0; i < n; i++)
    {
        cin >> v;
        birds.push_back(v);
    }
    sort(birds.begin(), birds.end());
    migratoryBirds(birds);

    return 0;
}