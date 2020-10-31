//Given a sorted array with repetition and an element x, we need to find index of last occurrence of x.

//Solution
//This is extension of Binary Search
#include<iostream>
using namespace std;
int binarySearch1(int *arr, int n, int x)
{
    //Iterative Approach
    int mid, low = 0, high = n-1;
    while(low<=high)
    {
        mid = (low + high)/2;
        if(arr[mid] == x)
        {
            if(mid==n-1 || arr[mid+1]!=arr[mid])
                return mid;
            else
                low = mid+1;
        }
        else if(arr[mid]>x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int binarySearch2(int *arr, int low, int high, int x, int n)
{
    //Recursive Approach
    if(low>high)
        return -1;
    int mid = (low + high)/2;
    if(arr[mid] == x)
    {
        if(mid==n-1 || arr[mid+1]!=arr[mid])
            return mid;
        else
        {
            return binarySearch2(arr, mid+1, high, x, n);
        }
        
    }
    else if(arr[mid]>x)
        return binarySearch2(arr, low, mid-1, x, n);
    else
        return binarySearch2(arr, mid+1, high, x, n);
}
int main()
{
    int n, x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>x;
    cout<<binarySearch1(arr, n, x)<<endl;
    cout<<binarySearch2(arr, 0, n-1, x, n)<<endl;
    return 0;
}