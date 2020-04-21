//Problem
//https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
//Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.



//Solution(Memoization)
#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];
int LCS(string a,string b,int p,int q)
{
    if(p==0 || q==0)
        return 0;
    else if(dp[p][q]!=-1)
        return dp[p][q];
    if(a[p-1]==b[q-1])
        return dp[p][q] = 1+LCS(a,b,p-1,q-1);
    else
        return dp[p][q] = max(LCS(a,b,p,q-1),LCS(a,b,p-1,q));
}
int main()
{
    int t;
    cin>>t;
    memset(dp,-1,sizeof(dp));
    int p,q;
    cin>>p>>q;
    string a,b;
    cin>>a>>b;
    cout<<LCS(a,b,p,q)<<endl;
    return 0;
}
