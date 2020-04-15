//Problem Statement
/*You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).*/


//Solution using top-down approach(Memoization)
#include<iostream>
#include<cstring>
using namespace std;
int dp[2000][2000];
int knapsack(int value[],int weight[],int W,int n)
{
    if(n==0 || W<=0)
        return 0;
    if(dp[n][W]!=-1)
        return dp[n][W];
    else if(weight[n-1]>W)
    {
        return dp[n][W] = knapsack(value,weight,W,n-1);
    }
    else if(weight[n-1]<=W)
    {
        return dp[n][W]=max((value[n-1]+knapsack(value,weight,W-weight[n-1],n-1)),knapsack(value,weight,W,n-1));
    }
    
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int *value = new int[n]();
    int *weight = new int[n]();
    int W;
    cin>>W;
    for(int i=0;i<n;i++)
	    cin>>value[i];
    for(int i=0;i<n;i++)
            cin>>weight[i];
    cout<<knapsack(value,weight,W,n)<<endl;
    return 0;
}










