#include<bits/stdc++.h>
#include<vector>
#include<climits>
using namespace std;

void print(vector<int> a,int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}

void printLIS(int *arr,int n)
{
	vector<vector<int>> LIS(n);
	
	LIS[0].push_back(arr[0]);
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && LIS[i].size() < LIS[j].size())
			{
				LIS[i] = LIS[j];
			}
		}
		LIS[i].push_back(arr[i]);
	}		
	
	vector<vector<int>> LDS(n);
	
	LDS[n-1].push_back(arr[n-1]);
	
	for(int i=n-2;i>=0;i--)
	{
		for(int j=n-1;j>i;j--)
		{
			if(arr[i]>arr[j] && LDS[i].size() < LDS[j].size())
			{
				LDS[i] = LDS[j];
			}
		}
		LDS[i].push_back(arr[i]);
	}
	
	for(int i=0;i<n;i++)
		reverse(LDS[i].begin(),LDS[i].end());
	
	
	int max = INT_MIN;
	int max_index = -1;
	
	
	for(int i=0;i<n;i++)
	{
		int temp = LIS[i].size()+LDS[i].size()-1;
		if(temp>max)
		{
			max  = temp;
			max_index = i;
		}
	}
	
	print(LIS[max_index],LIS[max_index].size()-1);
	print(LDS[max_index],LDS[max_index].size());
	cout<<endl;
}

int main()
{
	int n = 8;
	int arr[] = { 1, 11, 2, 10, 4, 5, 2, 1 };
	printLIS(arr,n);
	return 0;
}
