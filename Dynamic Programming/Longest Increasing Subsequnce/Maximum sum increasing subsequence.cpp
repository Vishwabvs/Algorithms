//https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0
//Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.


#include<iostream>
using namespace std;

int slis(int arr[],int n)
{
    int *lookup = new int[n];
    lookup[0] = arr[0];

    for(int i = 1;i<n;i++)
    {
        lookup[i] = arr[i];
        for(int j = 0;j<i;j++)
        {
            if(arr[i]>arr[j] && lookup[j]+arr[i]> lookup[i])
            {
                lookup[i] = lookup[j]+arr[i];
            }
        }
    }
    int max = -99999;
    for(int i=0;i<n;i++)
        if(max<lookup[i])
            max = lookup[i];

    return max;
}

int main()
 {
	int q;
	cin>>q;
	while(q--)
	{
	    int n;
	    cin>>n;
	    int *arr = new int[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    cout<<slis(arr,n)<<endl;
	}
	return 0;
}
