//Problem
//https://www.geeksforgeeks.org/coin-change-dp-7/
/*Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.*/


//Solution
#include<iostream>
using namespace std;
int main()
{
    int m;
    cin>>m;
    int arr[m],n;
    for(int i=0;i<m;i++)
        cin>>arr[i];
    cin>>n;
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++)
        dp[i][0]=1;
    for(int i=1;i<n+1;i++)
        dp[0][i]=0;
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
    	    if(arr[i-1]<=j)
    	        dp[i][j]=dp[i][j-arr[i-1]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[m][n]<<endl;
    return 0;
}
