#include<iostream>
#include<cstring>
#include<limits.h>
using namespace std;

int dp[101][101];

int mcm(int *arr,int i,int j)
{
    if(i>=j)    return 0;
    
    if(dp[i][j]!=-1)    return dp[i][j];
    
    int temp,min = INT_MAX;
    for(int k=i;k<j;k++)
    {
        temp = mcm(arr,i,k)+mcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(temp<min)
            min = temp;
    }
    return dp[i][j] = min;
}

int main()
{
    
    int n;
    cin>>n;
    int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<mcm(arr,1,n-1)<<endl;
	return 0;
}
