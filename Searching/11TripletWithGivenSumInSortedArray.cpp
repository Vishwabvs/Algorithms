//Given a sorted array and a sum, find if there is a triplet with given sum

#include<iostream>
using namespace std;
int findPair(int *arr, int left, int right, int sum)
{
    while(left<right)
    {
        if(arr[left]+arr[right]==sum)
            return true;
        else if(arr[left] + arr[right]>sum)
            right--;
        else
            left++;        
    }
    return false;
}
int findTriplet(int *arr, int n, int sum)
{
    for(int i=0;i<n;i++)
    {
        if(findPair(arr, i+1, n-1, sum - arr[i]))
            return true;
    }
    return false;
}
int main()
{
    int n, x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int sum;
    cin>>sum;
    cout<<findTriplet(arr, n, sum);
    return 0;
}