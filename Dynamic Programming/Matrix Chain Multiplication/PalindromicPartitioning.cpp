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

int minpalPartition(string str, int i, int j)
{
	if(i==j)
		return 0;
	else if(isPalindrome(str,i,j))
		return 0;
	int min = INT_MAX,temp;
	for(int k = i; k < j;k++)
	{
		temp = minpalPartition(str, i, k)+minpalPartition(str,k+1,j)+1;
		if(temp<min)
			min = temp;
	}
	return min;
}

int main()
{
	string str = "nitiekefefz";

	//cout<<isPalindrome("ABA",0,2)<<endl;
	cout<<minpalPartition(str,0,str.length()-1)<<endl;
	return 0;
}