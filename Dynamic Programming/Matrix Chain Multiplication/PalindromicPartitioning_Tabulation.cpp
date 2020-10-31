//https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/


#include<iostream>
#include<bits/stdc++.h>
#include<climits>
#include<cstring>
using namespace std;

int dp[1001][1001];

bool isPalindrome(string str, int i, int j)
{
	while(i<j)
	{
		if(str[i]==str[j])
		{
			i++;j--;
		}
		else
			return false;
	}
	return true;
}

int minpalPartition(string str, int n)
{
	int cut[n][n];
	bool pal[n][n];

	for(int i = 0; i<n;i++)
	{
		cut[i][i] = 0;
		pal[i][i] = true;
	}

	for(int l = 2; l <= n; l++)
	{
		for(int i = 0; i < n-l+1; i++)
		{
			int j = i+l-1;


			//If strlen==2, then check the first and last character.
			if(l == 2)
				pal[i][j] = (str[i] == str[j]);
			else	//if strlen!=2, check first and last characters and also the substring str[i+1 . . j-1]
				pal[i][j] = ((str[i] == str[j]) && pal[i+1][j-1]);	


			if(pal[i][j]==true)		//Substring str[i..j] is palindrome, then cut[i..j] will be 0
				cut[i][j] = 0;
			else
			{
				cut[i][j] = INT_MAX;
				for(int k = i; k < j; k++)
				{
					cut[i][j] = min(cut[i][j], (cut[i][k] + cut[k+1][j] + 1));
				}
			}

		}
	}
	return cut[0][n-1];
}

int main()
{
	string str = "nitiekefefz";

	//cout<<isPalindrome("ABA",0,2)<<endl;
	memset(dp,-1,sizeof(dp));
	cout<<minpalPartition(str,str.length())<<endl;
	return 0;
}