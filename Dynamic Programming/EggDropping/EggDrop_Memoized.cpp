#https://www.geeksforgeeks.org/dynamic-programming-set-11-egg-dropping-puzzle/


//Memoization
#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

int dp[100][100];

int eggdrop(int eggs, int floors)
{
    //if(eggs == 0)
      //  return 0;
    if(floors ==1 ||floors ==0)
        return floors;
    if(eggs == 1)
        return floors;
    if(dp[eggs][floors] !=-1)
        return dp[eggs][floors];
    int min = INT_MAX,res,i;
    for(i=1;i<=floors;i++)
    {
        res = max(eggdrop(eggs-1,i-1),eggdrop(eggs,floors-i));
        if(res<min)
            min = res;
    }
    return dp[eggs][floors] = (min+1);
}


int main()
{
    memset(dp,-1,sizeof(dp));
	int eggs,floors;
    cin>>eggs>>floors;
    cout<<eggdrop(eggs,floors)<<endl;
	return 0;
}
