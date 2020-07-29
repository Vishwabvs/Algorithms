#include<iostream>
#include<cstring>
#include<limits.h>
using namespace std;

int mcm(int *arr,int n)
{
	int dp[n+1][n+1];
	
	for(int i=1;i<=n;i++)
		dp[i][i] = 0;
		
	for(int len = 2; len<=n;len++)
	{
		for(int i=1;i<n-len+2;i++)
		{
			int j = i+len-1;
			dp[i][j] = INT_MAX;
			for(int k = i;j<n && k<=j-1;k++)
			{
				int cost = dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
				if(cost<dp[i][j])
					dp[i][j] = cost;
			}
		}
	}	
    return dp[1][n-1];
}
int main()
{
    
    int n = 4;
    int arr[]={10,30,5,60};
	cout<<mcm(arr,n)<<endl;
	return 0;
}
