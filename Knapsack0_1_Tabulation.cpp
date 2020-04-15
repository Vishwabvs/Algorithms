//Problem Statement
/*You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).*/

//Solution using Bottom-Up approach(Tabulation)
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *value = new int[n]();
    int *weight = new int[n]();
    int W;
    cin>>W;
    int dp[n+1][W+1];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
	    cin>>value[i];
    for(int i=0;i<n;i++)
            cin>>weight[i];
    for(int i=0;i<=n;i++)
	{
		dp[i][0]=0;
    }
    for(int i=0;i<=W;i++)
    {
    	dp[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=W;j++)
    	{
    		if(weight[i-1]<=j)
    		{
    			dp[i][j]=max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
    		}
    		else
    			dp[i][j]=dp[i-1][j];
    	}
    }
    cout<<dp[n][W]<<endl;
    return 0;
}

