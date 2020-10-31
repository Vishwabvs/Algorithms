//Given a sorted array and an element x, we need to count occurrences of x in the array.

//Solution
#include<iostream>
using namespace std;
int first(int *arr, int n, int x)
{
    //Iterative Approach
    int mid, low = 0, high = n-1;
    while(low<=high)
    {
        mid = (low + high)/2;
        if(arr[mid] == x)
        {
            if(mid==0 || arr[mid-1]!=arr[mid])
                return mid;
            else
                high = mid-1;
        }
        else if(arr[mid]>x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int last(int *arr, int n, int x)
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
int countOccur(int *arr, int n, int x)
{
    int firstOccur = first(arr, n, x);
    if(firstOccur == -1)
        return 0;
    int lastOccur = last(arr, n, x);
    return lastOccur-firstOccur+1;
}
int main()
{
    int n, x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>x;
    cout<<countOccur(arr, n, x)<<endl;
    return 0;
}