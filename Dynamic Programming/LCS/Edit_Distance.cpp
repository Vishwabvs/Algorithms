//https://www.geeksforgeeks.org/edit-distance-dp-5/
/*Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.
1. Insert
2. Delete
3. Replace*/

//Solution
#include<iostream>
using namespace std;

int min(int a,int b,int c)
{
    return min(min(a,b),c);
}

int lcs_func(string a,string b)
{
    int m = a.size();
    int n = b.size();
    
    int dp[m+1][n+1]={0};
    
    
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0)
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1+min(dp[i-1][j], dp[i][j-1],dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}


int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int edits = 0;
        int m,n;
        cin>>m>>n;
        string a,b;
        cin>>a>>b;
        
        cout<<lcs_func(a,b)<<endl;
    }
	return 0;
}
