//https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/


#include<iostream>
#include<climits>
using namespace std;

int lbs(int *arr,int n)
{
    int dp1[n];
    for(int i=0;i<n;i++)
        dp1[i] = 1;
    int max = INT_MIN;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && 1+dp1[j] > dp1[i])
            {
                dp1[i] = 1+dp1[j];
            }
        }
    }
    int dp2[n];
    for(int i=0;i<n;i++)
        dp2[i] = 1;
        
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(arr[i]>arr[j] && 1+dp2[j]>dp2[i])
            {
                dp2[i] = 1+dp2[j];
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        int temp = dp1[i]+dp2[i]-1;
        if(temp > max)
            max = temp;
    }
    return max;
}



int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<lbs(arr,n)<<endl;
	return 0;
}
