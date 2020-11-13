//Implementation of Radix Sort

//Implementation of Counting Sort

#include<iostream>
using namespace std;
void countingSort(int *arr, int n, int k)
{
    int brr[n];
    int c[10];
    for(int i = 0; i < 10; i++)
        c[i] = 0;
    for(int i = 0; i < n; i++)
        c[(arr[i]/k)%10]++;
    for(int i = 1; i < 10; i++)
    {
        c[i] = c[i - 1] + c[i];
    }
    for(int j = n - 1; j >= 0; j--)
    {
        brr[c[(arr[j]/k)%10] - 1] = arr[j];
        c[(arr[j]/k)%10]--;
    }
    for(int i = 0; i < n; i++)
        arr[i] = brr[i];
}
void radixSort(int* arr, int n)
{
    int max1 = arr[0];
    for(int i = 1; i < n; i++)
        max1 = max(max1, arr[i]);
    for(int exp = 1; (max1/exp) > 0; exp = exp*10)
        countingSort(arr, n, exp);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    radixSort(arr, n);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}