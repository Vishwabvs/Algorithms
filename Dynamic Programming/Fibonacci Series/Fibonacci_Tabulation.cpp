#include<iostream>
#include<time.h>
using namespace std;
int main()
{
    clock_t beg,en;
    double time_taken;
    int lookup[100];
    beg = clock();

    lookup[0] = 0;
    lookup[1] = 1;
    for(int i=2;i<=9;i++)
        lookup[i] = lookup[i-1] + lookup[i-2];
    cout<<lookup[9]<<endl;
    en = clock();
    time_taken = (double)(en - beg) / CLOCKS_PER_SEC;
    cout<<time_taken<<endl;
    return 0;
}
