//Implementation of Counting Sort

#include<iostream>
using namespace std;
void countingSort(int *arr, int n, int k)
{
    int brr[n];
    int c[k];
    for(int i = 0; i < k; i++)
        c[i] = 0;
    for(int i = 0; i < n; i++)
        c[arr[i]]++;
    for(int i = 1; i < k; i++)
    {
        c[i] = c[i - 1] + c[i];
    }
    for(int j = n - 1; j >= 0; j--)
    {
        brr[c[arr[j]] - 1] = arr[j];
        c[arr[j]]--;
    }
    for(int i = 0; i < n; i++)
        arr[i] = brr[i];
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int k;
    cin>>k;
    countingSort(arr, n, k);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}