//https://www.geeksforgeeks.org/printing-longest-common-subsequence/
//Problem
//Given two sequences, print the longest subsequence present in both of them.


//Solution
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
    int index = dp[p][q];
    char result[index+1];
    result[index]='\0';
    int i=p,j=q;
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            result[--index] = a[i-1];
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    cout<<result<<endl;
    return 0;
}
