//https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
/*The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.*/

//Solution (Naive approach):

#include<iostream>
#include<climits>
using namespace std;
int lis(int arr[], int n,int& max_len)
{
    if(n == 1)
        return 1;
    int res, max_ending_here = 1;
    for(int i=1;i<n;i++)
    {
        res = lis(arr,i,max_len);
        if(arr[i-1]<arr[n-1] && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
    if(max_len < max_ending_here)
        max_len = max_ending_here;
    return max_ending_here;
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_len = INT_MIN;
    lis(arr,n,max_len);
    cout<<"Length of longest subsequence is: "<<max_len<<endl;
    return 0;
}
