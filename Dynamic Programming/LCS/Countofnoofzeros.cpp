//https://www.geeksforgeeks.org/longest-sub-string-of-0s-in-a-binary-string-which-is-repeated-k-times/
//Given binary string S of size N and a number K. The task is to find the Longest sub string of 0’s in the string which is formed by //repeating given string K times.


#include<iostream>
using namespace std;
int main()
{
    string str;
    int n;
    cin>>str;
    cin>>n;

    int ans=0;
    int s = str.size();
    if(n>1)
    {
        str = str+str;
        n= n*2;
    }
    int i=0,x=0;
    while(i<n)
    {
        while(str[i]=='0'&&i<n)
        {
            x++;
            i++;
        }
        ans = max(ans, x);
        i++;
    }
    if(n==1 or ans!=s)
        cout<<ans;
    else
        cout<<ans/2*n;

    return 0;
}

