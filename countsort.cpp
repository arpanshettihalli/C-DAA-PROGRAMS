#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr)
{
    int n = arr.size();

    int maxi = *max_element(arr.begin(), arr.end());

    vector<int> count(maxi + 1, 0);

    for(int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    int index = 0;

    for(int i = 0; i <= maxi; i++)
    {
        while(count[i] > 0)
        {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}

int main()
{
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    countingSort(arr);

    for(int x : arr)
        cout << x << " ";

    return 0;
}