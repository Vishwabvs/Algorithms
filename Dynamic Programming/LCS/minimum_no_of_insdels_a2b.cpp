//Problem
//https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/
/*Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.*/


//Solution
#include<iostream>
#include<cstring>
using namespace std;
int lcs(string x,string y)
{
    int m=x.size();
    int n=y.size();
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++)
        dp[i][0]=0;
    for(int j=0;j<n+1;j++)
        dp[0][j]=0;
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(x[i-1]==y[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main()
{
    string x,y;
    int a,b;
    cin>>a>>b;
    cin>>x>>y;
    int sum = lcs(x,y);
    int m = a-sum;
    int n = b-sum;
    cout<<m+n<<endl;
	return 0;
}
