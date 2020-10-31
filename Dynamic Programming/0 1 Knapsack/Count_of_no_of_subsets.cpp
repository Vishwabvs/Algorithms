//Problem
//https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
//Given an array arr[] of length N and an integer X, the task is to find the number of subsets with sum equal to X.


//Solution
#include<iostream>
using namespace std;
int main()
{
	int n,sum;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>sum;
	int dp[n+1][sum+1];
	for(int i=0;i<n+1;i++)
		dp[i][0]=1;
	for(int i=1;i<sum+1;i++)
		dp[0][i]=0;
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(arr[i-1]<=sum)
			{
				dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
			}
			else 
				dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[n][sum];
	return 0;
}
