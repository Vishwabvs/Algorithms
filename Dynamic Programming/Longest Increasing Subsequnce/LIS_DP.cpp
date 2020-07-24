//https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
/*The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.*/

//Solution (DP):
#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
void lis(int arr[],int n,int& max_len)
{
    int *lookup = new int[n];
    lookup[0] = 1;
    for(int i = 1;i < n;i++)
    {
        lookup[i] = 1;
        for(int j = 0;j < i;j++)
        {
            if(arr[j]<arr[i] && lookup[j]+1 > lookup[i])
                lookup[i]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(lookup[i]>max_len)
            max_len = lookup[i];
    }
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
