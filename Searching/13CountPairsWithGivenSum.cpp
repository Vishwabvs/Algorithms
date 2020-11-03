//Given an array of integers, and a number ‘sum’, find the number of pairs of integers in the array whose sum is equal to ‘sum’
//https://www.geeksforgeeks.org/count-pairs-with-given-sum/

//Solution
#include<iostream>
using namespace std;
int countPairs(int *arr, int n, int sum)
{
    int count = 0, temp;
    int low = 0, high = n-1, mid;
    while(low<high)
    {
        
        temp = arr[low] + arr[high];
        if(temp == sum)
        {
            count++;
            low++;
            high--;
        }
        else if(count > sum)
            high--;
        else
            low++;        
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int sum;
    cin>>sum;
    cout<<countPairs(arr, n, sum)<<endl;
    return 0;
}