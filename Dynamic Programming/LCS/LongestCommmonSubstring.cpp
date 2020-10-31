//Problem
//https://www.geeksforgeeks.org/longest-common-substring-dp-29/
//Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.


//Solution
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int p,q;
    cin>>p>>q;
    string a,b;
    cin>>a>>b;
    int dp[p+1][q+1];
    for(int i=0;i<p+1;i++)
        dp[i][0]=0;
    for(int i=0;i<q+1;i++)
        dp[0][i]=0;
    int result = 0;
    for(int i=1;i<p+1;i++)
    {
        for(int j=1;j<q+1;j++)
        {
    	    if(a[i-1]==b[j-1])
    	    {
                dp[i][j] = 1+dp[i-1][j-1];
                if(dp[i][j]>result)
                    result = dp[i][j];
    	    }
            else
                dp[i][j] = 0;
        }
    }
    cout<<result<<endl;
    return 0;
}
