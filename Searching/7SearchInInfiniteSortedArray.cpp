//Given a sorted array, find whether a given element is present or not.

//Solution
#include<iostream>
using namespace std;
int infiniteSearch(int *arr, int x)
{
    //Naive Approach
    int i=0;
    while(true)
    {
        if(arr[i]==x)
            return i;
        else if(arr[i]>x)
            return -1;
        i++;
    }
}
int binarySearch(int *arr, int low, int high, int x)
{
    if(low>high)
        return -1;
    int mid = (low+high)/2;
    if(arr[mid] == x)
        return mid;
    else if(arr[mid]>x)
        return binarySearch(arr, low, mid-1, x);
    else    
        return binarySearch(arr, mid+1, high, x);
}
int infiniteSearch_efficient(int *arr, int x)
{
    //Efficient Approach
    if(arr[0] == x) return 0;
    int i=1;
    while(arr[i] < x)
        i = i*2;
    if(arr[i] == x)
        return i;
    return binarySearch(arr, i/2, i, x);
      
}
int main()
{
    int n, x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>x;
    cout<<infiniteSearch_efficient(arr, x);
    return 0;
}