//Problem
//https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
/*Given an array with non negative integers and a sum value, determine whether there is a subset present in that array such that the elements in the subset add upto sum*/


//Solution using bottom up approach


#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,sum,arr[10];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>sum;
	bool dp[n+1][sum+1];
	for(int i=0;i<n+1;i++)
	{
		dp[i][0]=true;
	}
	for(int i=1;i<sum+1;i++)
	{
		dp[0][i]=false;
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(arr[i-1]<=j)
				dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[n][sum]<<endl;
}

