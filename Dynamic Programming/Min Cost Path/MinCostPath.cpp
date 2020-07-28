//https://www.geeksforgeeks.org/min-cost-path-dp-6/
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int m=3,n=3;
    //cin>>m>>n;
    int arr[m][n] = {{1,2,3},{4,8,2},{1,5,3}};

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            //cin>>arr[i][j];
        }
    }

    int dp[m][n];
    dp[0][0] = arr[0][0];
    for(int i=1;i<m;i++)
    {
        dp[i][0] = dp[i-1][0] + arr[i][0];
    }
    for(int i=1;i<n;i++)
    {
        dp[0][i] = dp[0][i-1] + arr[0][i];
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j] = arr[i][j] + min(min(dp[i-1][j],dp[i][j-1]), dp[i-1][j-1]);
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[m-1][n-1]<<endl;
    return 0;
}
