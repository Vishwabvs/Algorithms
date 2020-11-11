//Given arrival and departure time of Guests, find the maximum number of guests u can meet at a time

#include<iostream>
#include<algorithm>
using namespace std;
int maxGuests(int *arr, int *dept, int n)
{
    sort(arr, arr + n);
    sort(dept, dept + n);
    int i = 1, j = 0, res = 1, curr = 1;
    while(i < n && j < n)
    {
        if(arr[i] <= dept[j])
        {
            curr++;
            i++;
        }
        else
        {
            curr--;
            j++;
        }
        res = max(curr, res);
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    int dept[n];
    for(int i = 0; i < n; i++)
        cin>>dept[i];
    
    cout<<maxGuests(arr, dept, n)<<endl;
    return 0;
}