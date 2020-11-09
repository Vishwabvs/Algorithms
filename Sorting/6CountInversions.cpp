#include<iostream>
using namespace std;
int countInversions(int* arr, int n)
{
    //O(n*n) approach
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
                res++;
        }
    }
    return res;
}
int merge(int* a, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int arr[n1];
    int brr[n2];
    for(int i = 0; i < n1; i++)
    {
        arr[i] = a[low + i];
    }
    for(int j = 0; j < n2; j++)
    {
        brr[j] = a[mid + 1 + j];
    }
    int i = 0, j = 0, k = low;
    int res = 0;
    while(i < n1 && j< n2)
    {
        if(arr[i] > brr[j])
        {
            res += n1 - i;
            a[k++] = brr[j++];
        }
        else
        {
            a[k++] = arr[i++];
        }
    }
    while(i < n1)
    {
        a[k++] = arr[i++];
    }
    while(j < n2)
    {
        a[k++] = brr[j++];
    }
    return res;
}
int countInversions2(int* arr, int low, int high)
{
    int res = 0;
    if(low < high)
    {
        int mid = low + (high - low) / 2;
        res += countInversions2(arr, low, mid);
        res += countInversions2(arr, mid + 1, high);
        res += merge(arr, low, mid, high);
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
    cout<<countInversions2(arr, 0, n-1)<<endl;
    return 0;
}