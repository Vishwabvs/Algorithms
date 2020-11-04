#include<iostream>
#include<climits>
using namespace std;
int sum(int* arr, int start, int end)
{
    int total = 0;
    for(int i=start; i<=end; i++)
        total += arr[i];
    return total;
}
int minPages(int *arr, int n, int k)
{
    if(k == 1)
        return sum(arr, 0, n - 1);
    if(n == 1)
        return arr[0];
    int res = INT_MAX;
    for(int i=1;i<n;i++)
    {
        res = min(res, max(minPages(arr, i, k-1), sum(arr, i, n-1)));
    }
    return res;
}
int minPages_bsearch(int* arr, int n, int k)
{
    int total_pages = sum(arr, 0, n-1);
    int max_pages = INT_MIN;
    for(int i=0;i<n;i++)
        if(arr[i]>max_pages)
            max_pages = arr[i];
    int res = 0;
    int low = max_pages, high = total_pages, mid;
    while(low <= high)
    {
        mid = (low + high)/2;
        int curr_sum = 0;
        int req_students = 1;
        for(int i=0;i<n;i++)
        {
            if(curr_sum + arr[i] > mid)
            {
                req_students++;
                curr_sum = arr[i];
            }
            else
            {
                curr_sum += arr[i];
            }       
        }
        if(req_students <= k)
        {
            res =  mid;
            high = mid - 1;
        }
        else 
        {
            low = mid + 1;
        }
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    cout<<minPages_bsearch(arr, n, k)<<endl;
    return 0;
}