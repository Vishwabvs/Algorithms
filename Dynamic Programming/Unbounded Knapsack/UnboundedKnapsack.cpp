//Problem
//https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/
/*Given weights and values related to n items and the maximum capacity allowed for these items. What is the maximum value we can achieve if we can pick any weights any number of times for a total allowed weight of W?*/


//Solution
#include<iostream>
using namespace std;
int main()
{
	int n,W;
    cin>>n>>W;
    int weight[n],value[n];
    for(int i=0;i<n;i++)
        cin>>value[i];
    for(int i=0;i<n;i++)
        cin>>weight[i];
    int dp[n+1][W+1];
    for(int i=0;i<n+1;i++)
        dp[i][0]=0;
    for(int i=1;i<W+1;i++)
        dp[0][i]=0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
	        if(weight[i-1]<=j)
	            dp[i][j]=max(value[i-1]+dp[i][j-weight[i-1]],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][W]<<endl;
	return 0;
}
