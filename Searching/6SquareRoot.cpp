//Given an integer, we need to find floor of its square root

int sqRoot1(int n)
{
    //O(n^1/2) solution
    int i=1;
    while(i*i<=n)
    {
        i++;
    }
    return i-1;
}
int sqRoot2(int n)
{
    int low = 1, high = n;
    int ans = -1, mid;
    while(low<=high)
    {
        mid = (low + high)/2;
        int sqNo = mid*mid;
        if(sqNo==n)
        {
            return mid;
        }
        else if(sqNo>n)
        {
            high = mid - 1;  
        }
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n; 
    cout<<sqRoot2(n)<<endl; 
    return 0;
}