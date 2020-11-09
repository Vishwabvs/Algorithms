//Given an unsorted array, write the partition function of the quicksort where last element is the pivot

//Solutuion
#include<iostream>
using namespace std;

int hoarePartition(int* arr, int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while(true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if(i >= j)
            return j;
        swap(arr[i], arr[j]);        
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int index = hoarePartition(arr, 0, n - 1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}