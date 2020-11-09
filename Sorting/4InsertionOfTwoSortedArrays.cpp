//Given two Sorted arrays, find the common distinct elements

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void findIntersection2(int *arr, int m, int *brr, int n)
{
    //O(n*n) approach
    for(int i = 0; i < m; i++)
    {
        if(i > 0 && arr[i-1] == arr[i])
            continue;
        for(int j = 0; j < n; j++)
        {
            if(arr[i] == brr[j])
            {
                cout<<arr[i]<<" ";
                break;
            }
        }
    }
    cout<<endl;
}

void findIntersection(int *arr, int m, int *brr, int n)
{
    
    int i = 0, j = 0;
    while(i < m && j < n)
    {
        if(i > 0 && arr[i - 1] == arr[i])
        {
            i++;
            continue;
        }
        if(arr[i] == brr[j])
        {
            cout<<arr[i]<<" ";
            i++;j++;
        }
        else if(arr[i] < brr[j])
        {
            i++;
        }
        else
        {
            j++;
        }
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
    findIntersection2(arr, m, brr, n);
    findIntersection(arr, m, brr, n);
    return 0;
}