//Given an array of size n, find the position of peak elements
//Peak element is one that is not smaller than the neighbors
#include<iostream>
using namespace std;
int findPeak(int *arr, int n)
{
    //O(n) approach
    if(n==1)
        return arr[0];
    if(arr[0]>arr[1])
        return arr[0];
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            return arr[i];
    }
    if(arr[n-1]>arr[n-2])
        return arr[n-1];
    return -1;
}
int findPeak_efficient(int *arr, int n)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        
    }
}
int main()
{
    int n, x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<findPeak(arr, n);
    return 0;
}