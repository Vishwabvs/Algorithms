#include<iostream>
#include<algorithm>
using namespace std;
bool findpairwithgivensum(int arr[], int index, int sum)
{
    int left = 0, right = index;
    int curr = 0;
    while(left < right)
    {
        if(arr[left] + arr[right] == sum)
            return true;
        else if(arr[left] + arr[right] > sum)
            right--;
        else
            left++;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int sum;
    cin>>sum;
    sort(arr, arr + n);
    cout<<findpairwithgivensum(arr, n - 1, sum)<<endl;
    return 0;
}