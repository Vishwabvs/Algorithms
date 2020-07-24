//Problem
//https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
//Given a sequence, find the length of the longest palindromic subsequence in it.

//Solution
#include<iostream>
#include<cstring>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a;
    b=a;
    reverse(b.begin(),b.end());
    int p = a.size();
    int q = b.size();
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
