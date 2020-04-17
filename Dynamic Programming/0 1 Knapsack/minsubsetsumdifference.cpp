//Problem
//*Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.


//Solution
#include<iostream>
#include<limits.h>
using namespace std;
int main()
 {
	int n,sum=0;
    cin>>n;
	int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        sum+=arr[i];
    bool dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
        dp[i][0]=true;
    for(int i=1;i<sum+1;i++)
        dp[0][i]=false;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
            else 
                dp[i][j]=dp[i-1][j];
	    }
	}
	int temp[int(sum/2)+1];
    int k=0;
    for(int i=0;i<=sum/2;i++)
    {	        
       if(dp[n][i])
            temp[k++]=i;
    }
    int mn=INT_MAX;
    for(int i=0;i<k;i++)
    {
        mn=min(mn,sum-(2*temp[i]));   
    }
    cout<<mn<<endl;
	return 0;
}
