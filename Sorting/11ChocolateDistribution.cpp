/*Given an array of n integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that: 
- Each student gets one packet.
- The difference between the number of chocolates in the packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.*/

//Solution
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int distribute(int* arr, int n, int m)
{
    //O(n log n) Approach
    if(m > n)
        return -1;
    sort(arr, arr + n);
    int res = INT_MAX;
    for(int i = 0; i < n - m + 1; i++)
    {
        res  = min(res, arr[i + m - 1] - arr[i]);
    }
    return res;
}
int main()
{
    int n, m;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cin>>m;
    cout<<distribute(arr, n, m)<<endl;   
    return 0;
}