//#https://www.geeksforgeeks.org/dynamic-programming-set-11-egg-dropping-puzzle/


//Tabulation
#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

int eggdrop(int eggs, int floors)
{
    int dp[eggs+1][floors+1];

    for(int i=1;i<=eggs;i++)
        dp[i][0] = 0;
    for(int i=1;i<=floors+1;i++)
        dp[0][i] = 0;

    for(int i=1;i<=floors;i++)
        dp[1][i] = i;
    for(int i=1;i<=eggs;i++)
        dp[i][1] = 1;

    for(int i=2;i<=eggs;i++)
    {
        for(int j=2;j<=floors;j++)
        {
            int min = INT_MAX;
            for(int k=1;k<=j;k++)
            {
                int res = 1+max(dp[i][j-k],dp[i-1][k-1]);
                if(min>res)
                    min = res;
            }
            dp[i][j] = min;
        }
    }
    return dp[eggs][floors];
}


int main()
{
	int eggs,floors;
    cin>>eggs>>floors;
    cout<<eggdrop(eggs,floors)<<endl;
	return 0;
}
