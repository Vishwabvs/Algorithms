//Problem
//Given an array find no of subarrays with given difference.


//Solution
#include<iostream>
using namespace std;
int subsetsum(int arr[],int n,int sum)
{
	int dp[n+1][sum+1];
	for(int i=0;i<n+1;i++)
		dp[i][0]=1;
	for(int i=1;i<sum+1;i++)
		dp[0][i]=0;
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(arr[i-1]<=j)
				dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][sum];
}
int main()
{
	int n,diff,sum=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>diff;
	for(int i=0;i<n;i++)
		sum+=arr[i];	
	cout<<subsetsum(arr,n,(diff+sum)/2)<<endl;
	return 0;
}
