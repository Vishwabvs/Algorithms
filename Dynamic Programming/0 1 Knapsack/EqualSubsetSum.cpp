//Problem
//https://www.geeksforgeeks.org/partition-problem-dp-18/
/*Given an array with non negative integers and a sum value, determine whether there is a subset present in that array such that the elements in the subset add upto sum*/


//Solution using bottom up approach
#include<iostream>
#include<cstring>
using namespace std;
int subsetsum(int arr[],int sum,int n)
{
    //cout<<sum<<endl;
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
	return dp[n][sum];
}


int main()
{
	int t,temp,n,sum=0,arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t;
	    sum+=t;
	    arr[i]=t;
	}
	if(sum%2==0)
	    if(subsetsum(arr,sum/2,n))
	        cout<<"YES"<<endl;
	    else
	        cout<<"NO"<<endl;
	else
	    cout<<"NO"<<endl;
	return 0;
}

