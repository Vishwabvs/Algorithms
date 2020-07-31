#include<iostream>
using namespace std;

int findbinomial(int n, int r)
{
    int dp[n+1][r+1]={-1};
    int p = 1000000007;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<=r && j<=i;j++)
        {
            if(j==0 || i==j)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = (dp[i-1][j-1]%p + dp[i-1][j]%p)%p;
            }
        }
    }
    return dp[n][r];
}

int main()
{
	int n,r;
	cin>>n>>r;
	cout<<findbinomial(n,r)<<endl;
	return 0;
}
