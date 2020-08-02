//https://www.geeksforgeeks.org/maximum-sum-bi-tonic-sub-sequence/



#include<iostream>
#include<climits>
using namespace std;

int sumlbs(int *arr,int n)
{
    int dp1[n],dp2[n];
    for(int i=0;i<n;i++)
    {
        dp1[i] = arr[i];
        dp2[i] = arr[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && arr[i]+dp1[j]>dp1[i])
                dp1[i] = dp1[j]+arr[i];
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(arr[i]>arr[j] && arr[i]+dp2[j]>dp2[i])
                dp2[i] = dp2[j]+arr[i];
        }
    }
    int max = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int temp = dp1[i]+dp2[i]-arr[i];
        if(temp>max)
            max = temp;
    }
    return max;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    cout<<sumlbs(arr,n)<<endl;
	}
	return 0;
}
