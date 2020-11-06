//Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be adjacent in the array. So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7)
//https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/

//Solution
#include<iostream>
using namespace std;
int maxSum(int* arr, int n)
{
    int incl = arr[0]; 
    int excl = 0; 
    int excl_new; 
    int i; 
  
    for (i = 1; i < n; i++) 
    { 
        excl_new = (incl > excl)? incl: excl; 
  
    
        incl = excl + arr[i]; 
        excl = excl_new; 
    } 
  
   
    return ((incl > excl)? incl : excl);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<maxSum(arr, n)<<endl;
}