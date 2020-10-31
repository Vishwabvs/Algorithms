//Given a sorted binary array and an element x, we need to count occurrences of 1 in the array.

//Solution
#include<iostream>
using namespace std;
int CountOnes(int *arr, int n, int x)
{
    //Iterative Approach
    int mid, low = 0, high = n-1;
    while(low<=high)
    {
        mid = (low + high)/2;
        if(arr[mid] == x)
        {
            if(mid==0 || arr[mid-1]!=arr[mid])
                return n-mid;
            else
                high = mid-1;
        }
        else if(arr[mid]>x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}
int main()
{
    int n, x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<CountOnes(arr, n, 1)<<endl;
    return 0;
}