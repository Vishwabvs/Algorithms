//Given two sorted arrays a and b of sizes m and n respectively, merge them and produce a sorted array of size m+n

//Solution
#include<iostream>
using namespace std;

void merge(int *arr, int m, int *brr, int n, int *res)
{
    int i = 0, j = 0, k = 0;
    while(i < m && j< n)
    {
        if(arr[i] > brr[j])
        {
            res[k++] = brr[j++];
        }
        else
        {
            res[k++] = arr[i++];
        }
    }
    while(i < m)
    {
        res[k++] = arr[i++];
    }
    while(j<n)
    {
        res[k++] = brr[j++];
    }
}


int main()
{
    int m, n;
    cin>>m;
    int arr[m];
    for(int i = 0; i < m; i++)
        cin>>arr[i];
    
    cin>>n;
    int brr[n];
    for(int i = 0; i < n; i++)
        cin>>brr[i];
    
    int res[m + n];
    merge(arr, m, brr, n, res);
    for(int i = 0; i < m+n; i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}