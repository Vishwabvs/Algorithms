#include<iostream>
#include<time.h>
#include<iomanip>
using namespace std;
int fib(int n)
{
    if(n<=1)
        return n;
    else
        return fib(n-1)+fib(n-2);
}

int main()
{
    clock_t beg,en;
    double time_taken;
    beg = clock();
    cout<<fib(9)<<endl;
    en = clock();
    time_taken = double(en-beg);
    cout<<(double)(en - beg) / CLOCKS_PER_SEC;
    return 0;
}
