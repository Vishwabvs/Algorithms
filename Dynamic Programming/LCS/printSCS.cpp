//https://www.geeksforgeeks.org/printing-longest-common-subsequence/
//Problem
/*Compute the shortest string for a combination of two given strings such that the new string consist of both the strings as its subsequences.*/


//Solution
#include<iostream>
#include<cstring>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
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
    int index = dp[p][q];
    string res;
    int i=p,j=q;
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            res.push_back(a[i-1]);
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            res.push_back(a[i-1]);
            i--;
        }
        else
        {
            res.push_back(b[j-1]);
            j--;
        }
    }
    while(i)
    {
        res.push_back(a[i-1]);
        i--;
    }
    while(j)
    {
        res.push_back(b[j-1]);
        j--;
    }
    
    reverse(res.begin(),res.end());
    //reverse(str.begin(), str.end());
    cout<<res<<endl;
    return 0;
}
