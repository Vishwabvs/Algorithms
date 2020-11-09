//Given an array, sort the array using merge sort

//Solution
#include<iostream>
using namespace std;
void merge(int *a, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int arr[n1];
    int brr[n2];
    for(int i = 0; i < n1; i++)
    {
        arr[i] = a[low + i];
    }
    for(int j = 0; j < n2; j++)
    {
        brr[j] = a[mid + 1 + j];
    }
    int i = 0, j = 0, k = low;
    while(i < n1 && j< n2)
    {
        if(arr[i] > brr[j])
        {
            a[k++] = brr[j++];
        }
        else
        {
            a[k++] = arr[i++];
        }
    }
    while(i < n1)
    {
        a[k++] = arr[i++];
    }
    while(j < n2)
    {
        a[k++] = brr[j++];
    }
}
void mergeSort(int *arr, int low, int high)
{
    if(low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    mergeSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}