//Given a sorted rotated array and an element x, find it position in log(n) time
//https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

#include<iostream>
using namespace std;
int rsearch(int *arr, int low, int high, int x)
{
    int mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid] == x)
            return mid;
        if(arr[mid]>arr[low])
        {
            if(x<arr[mid] && x>=arr[low])
                high = mid - 1;
            else    
                low = mid + 1;
        }
        else 
        {
            if(x>arr[mid] && x<=arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>x;
    cout<<rsearch(arr, 0, n-1, x);
    return 0;
}