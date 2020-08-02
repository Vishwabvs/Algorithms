//https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/

#include<iostream>
#include<bits/stdc++.h>
#include<climits>
#include<cstring>
using namespace std;

int minpalPartition(string str, int n)
{
	int cut[n];
	bool pal[n][n];

	for(int i = 0; i<n;i++)
	{
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
		}
	}

	for(int i = 0; i < n; i++)
	{
		if(pal[0][i] == true)
		{
			cut[i] = 0;
		}
		else
		{
			cut[i] = INT_MAX;
			for(int j = 0; j < i; j++)
			{
				if(pal[j+1][i] == true && (1 + cut[j] < cut[i]))
					cut[i] = 1 + cut[j];
			}
		}
	}
	return cut[n-1];
}

int main()
{
	string str = "nitiekefefz";

	//cout<<isPalindrome("ABA",0,2)<<endl;
	memset(dp,-1,sizeof(dp));
	cout<<minpalPartition(str,str.length())<<endl;
	return 0;
}