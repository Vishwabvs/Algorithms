//Given an unsorted array, write the partition function of the quicksort where last element is the pivot
//Input: arr[] = {3 8 6 12 10 7}  
//Expected Output: arr[] = {6 3 7 8 12 10}   (7 at its correct place)

//Solutuion
#include<iostream>
using namespace std;

void naivePartition(int* arr, int l, int h, int pivot)
{
    int temp[h - l + 1];
    int k = 0;
    for(int i = l; i < h; i++)
    {
        if(arr[i] <= arr[pivot])
            temp[k++] = arr[i];
    }
    temp[k++] = arr[pivot];
    for(int i = l; i < h; i++)
    {
        if(arr[i] > arr[pivot])
            temp[k++] = arr[i];
    }
    for(int i = 0 ; i < k; i++)
    {
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    naivePartition(arr, 0, n - 1, n - 1);
    return 0;
}