#include <bits/stdc++.h>
using namespace std;
int partition(vector<int>& arr, int low, int high)
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    while(true)
    {
        while(i<=high && arr[i]<=pivot)
        {
            i++;
        }
        while(j>low && arr[i]>pivot)
        {
            j--;
        }
        if(i>=j)
            break;
        swap(arr[i], arr[j]);

    }
    swap(arr[low], arr[j]);

    return j;
}
void quickSort(vector<int>& arr, int low, int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
int main()
{
    vector<int> arr = {5, 2, 8, 1, 9, 3};

    quickSort(arr, 0, arr.size() - 1);

    for(int x : arr)
        cout << x << " ";

    return 0;
}