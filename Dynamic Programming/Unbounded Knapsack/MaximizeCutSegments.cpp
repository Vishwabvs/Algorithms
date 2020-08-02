//https://practice.geeksforgeeks.org/problems/cutted-segments/0


#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int rodcut(int n,int x,int y,int z)
{
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    for(int i=0;i<n+1;i++)
    {
        if(dp[i]!=-1)
        {
            if(i+x<=n)
                dp[i+x] = max(dp[i+x],dp[i]+1);
            if(i+y<=n)
                dp[i+y] = max(dp[i+y],dp[i]+1);
            if(i+z<=n)
                dp[i+z] = max(dp[i+z],dp[i]+1);
        }
    }
    return dp[n];
}


int main()
{
    int n;
    cin>>n;
    int x,y,z;
    cin>>x>>y>>z;
    cout<<rodcut(n,x,y,z)<<endl;
	return 0;
}
