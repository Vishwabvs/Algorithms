#include<iostream>
#include<time.h>
using namespace std;
int lookup[25];
int fib(int n)
{
    if(lookup[n] == -1)
    {
        if(n<=1)
            lookup[n] = n;
        else
            lookup[n] = fib(n-1) + fib(n-2);
    }
    return lookup[n];
}
int main()
{
    clock_t beg,en;
    for(int i=0;i<25;i++)
        lookup[i] = -1;
    beg = clock();
    cout<<fib(9)<<endl;
    en = clock();
    cout<<(double)(en - beg) / CLOCKS_PER_SEC;
    return 0;
}
