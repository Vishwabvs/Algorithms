//Problem
//https://www.geeksforgeeks.org/shortest-common-supersequence/
//Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.

//Solution
#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];
int LCS(int p,int q,string x,string y)
{
    if(p==0 ||q==0)
        return 0;
    if(dp[p][q]!=-1)
        return dp[p][q];
    if(x[p-1]==y[q-1])
        return dp[p][q] = 1+LCS(p-1,q-1,x,y);
    else
        return dp[p][q] = max(LCS(p-1,q,x,y),LCS(p,q-1,x,y));
}
int main()
{
	memset(dp,-1,sizeof(dp));
    string x,y;
    cin>>x>>y;
    int p,q;
    p = x.size();
    q = y.size();
    int lcs = LCS(p,q,x,y);
    cout<<p+q-lcs<<endl;
}
