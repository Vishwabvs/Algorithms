//Given a sorted array and a sum, find if there is a pair with given sum

//Solution using Two Pointer Technique
#include<iostream>
using namespace std;
//This method works only if the array is sorted... If the array is unsorted hashing is the best technique...
int findPair(int *arr, int n, int sum)
{
    
    int left = 0, right = n - 1;
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
int main()
{
    int n, x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int sum;
    cin>>sum;
    cout<<findPair(arr, n, sum);
    return 0;
}