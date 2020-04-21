//Problem
//https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
//Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.


//Solution(Tabulation)
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int p,q;
    cin>>p>>q;
    string a,b;
    cin>>a>>b;
    int dp[p+1][q+1];
    for(int i=0;i<p+1;i++)
        dp[i][0]=0;
    for(int i=0;i<q+1;i++)
        dp[0][i]=0;
    for(int i=1;i<p+1;i++)
    {
        for(int j=1;j<q+1;j++)
        {
    	    if(a[i-1]==b[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[p][q]<<endl;
    return 0;
}
