//Problem
//https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
/*Given a value V. You have to make change for V cents, given that you have infinite supply of each of C{ C1, C2, .. , Cm} valued coins. Find the minimum number of coins to make the change.*/


//Solution
#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n,sum,i,j;
    cin>>sum>>n;
    int coin[n];
    for(i=0;i<n;i++)
        cin>>coin[i];
    int dp[n+1][sum+1];
    //Initialization for 1st row and 1st column
    for(i=0;i<sum+1;i++)
        dp[0][i]=INT_MAX-1;
    for(i=1;i<n+1;i++)
        dp[i][0]=0;
    //Initialization for 2nd row
	for(i=1,j=1;j<=sum;j++)
    {
        if(j%coin[0]==0)
            dp[i][j]=j/coin[0];
        else
            dp[i][j]=INT_MAX-1;
    }
    //Main code
    for(i=2;i<n+1;i++)
    {
        for(j=1;j<sum+1;j++)
        {
    	    if(coin[i-1]<=j)
     	       dp[i][j]=min(1+dp[i][j-coin[i-1]],dp[i-1][j]);
     	    else
               dp[i][j]=dp[i-1][j];
        }
    }
    if(dp[n][sum]==INT_MAX-1)
        cout<<-1<<endl;
    else
        cout<<dp[n][sum]<<endl;
    return 0;
}
