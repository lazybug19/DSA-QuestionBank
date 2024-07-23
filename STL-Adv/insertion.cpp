#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n) {
    for (int i = 1; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) { //AO
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertion_sort(arr, n);
    return 0;
}


//not insertion

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    v = {3, 4, 5, 1, 2};
    for(int j = 0; j < v.size(); j++)
    {
        int i = j;
        while(i < v.size()-1)
        {
            if(v[i] < v[i+1])
                swap(v[i], v[i+1]);
            if(i>0 && v[i] > v[i-1])
                swap(v[i], v[i-1]);
            i++;
        }
    }
    cout << v[0] << v[1] << v[2] << v[3] << v[4];
    
    return 0;
}

}
