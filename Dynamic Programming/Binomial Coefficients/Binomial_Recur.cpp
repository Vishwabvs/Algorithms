#include<iostream>
#include<cstring>
using namespace std;
int binomial(int n,int k)
{
    if(k==0 || n==k)
        return 1;
    return binomial(n-1,k-1)+binomial(n-1,k);
}

int main()
{
    int k,n;
    cin>>n>>k;
    cout<<binomial(n,k)<<endl;
	return 0;
}
