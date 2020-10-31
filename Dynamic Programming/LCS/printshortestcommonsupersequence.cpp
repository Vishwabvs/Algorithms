//Problem
//Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.
//https://www.geeksforgeeks.org/shortest-common-supersequence/


//Solution
#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;
	int m = a.size();
	int n = b.size();
	int dp[m+1][n+1];
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(a[i-1]==b[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int p=m,q=n;
	string res;
	while(p>0 && q>0)
	{
		if(a[p-1]==b[q-1])
		{
			res = res + a[p-1];
			p--;q--;
		}
		else if(dp[p-1][q]>dp[p][q-1])
		{
			res = res + a[p-1];
			res = res + b[q-1];
			p--;
		}
		else
		{
			res = res + a[p-1];
			res = res + b[q-1];
			q--;
		}
	}
	reverse(res.begin(),res.end());
	cout<<res<<endl;
	return 0;
}
