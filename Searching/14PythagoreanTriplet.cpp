//Given an array arr of N integers, write a function that returns true if there is a triplet (a, b, c) 
//that satisfies a2 + b2 = c2, otherwise false
//https://www.geeksforgeeks.org/find-pythagorean-triplet-in-an-unsorted-array/


//Solution
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isPair(int arr[], int low, int high, int sum)
{
    while(low<high)
    {
        if(arr[low]+arr[high] == sum)
            return true;
        if(arr[low]+arr[high] > sum)
            high--;
        else
            low++;
    }
    return false;
}
bool checkTriplet(int arr[], int n) {
    // code here
    for(int i=0;i<n;i++)
        arr[i] = arr[i]*arr[i];
    
    sort(arr, arr+n);     
        
    for(int i=n-1;i>=2;i--)
    {
        if(isPair(arr, 0, i-1, arr[i]))
            return true;
	}
	return false;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<checkTriplet(arr, n)<<endl;
    return 0;
}