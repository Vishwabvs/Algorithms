#include<iostream>
using namespace std;

int maximum(int a,int b,int c)
{
    return max(max(a,b),c);
}

int main()
{
	int q;
	cin>>q;
	while(q--)
	{
	    int n;
	    int matrix[50][50];
	    cin>>n;
	    for(int i=0;i<n;i++)
	        for(int j=0;j<n;j++)
	            cin>>matrix[i][j];
	    int dp[50][50] = {0};
	    for(int i=0;i<=n;i++)
	    {
	        dp[i][0] = 0;
	        dp[0][i] = 0;
	    }
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=n;j++)
	        {
	            dp[i][j] = matrix[i-1][j-1]+maximum(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]);
	        }
	    }
	    int max = -9999;
	    for(int i=0;i<=n;i++)
	    {
	        if(max<dp[n][i])
	            max = dp[n][i];
	    }
	    cout<<max<<endl;
	}
	return 0;
}
