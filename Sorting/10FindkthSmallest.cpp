//Given an array of size n, find the kth smallest element

//Solution
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int* arr, int n, int k)
{
    //O(n log n) approach
    sort(arr, arr + n);
    return arr[k - 1];
}
int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i, j = low - 1;
    for(i = low; i < high - 1; i++)
    {
        if(arr[i] <= pivot)
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    j++;
    swap(arr[i], arr[j]);
    return j;
}
int kthSmallest2(int* arr, int n, int k)
{
    //O(n*n) approach
    int low = 0, high = n - 1, pivot;
    while(low <= high)
    {
        pivot = partition(arr, low, high);
        if(pivot == k - 1)
            return pivot;
        if(pivot > k - 1)
            high = pivot - 1;
        else 
            low = pivot + 1;
    }
    return -1;
}
int main()
{
    int n, k;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cin>>k;
    int res = kthSmallest2(arr, n, k);
    if(res == -1)
        cout<<"Invalid"<<endl;
    else
        cout<<arr[res]<<endl;    
    return 0;
}