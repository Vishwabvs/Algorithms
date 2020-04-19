//Problem
//https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
/*Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.*/


//Solution
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int length[n],price[n];
	for(int i=0;i<n;i++)
	    cin>>price[i];
	for(int i=1;i<=n;i++)
	    length[i-1]=i;
    int dp[n+1][n+1];
    for(int i=0;i<n+1;i++)
    {
        dp[i][0]=0;
        dp[0][i]=0;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
    	    if(length[i-1]<=j)
    	        dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][n]<<endl;
	return 0;
}
