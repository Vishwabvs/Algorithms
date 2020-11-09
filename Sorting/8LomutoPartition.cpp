//Given an unsorted array, write the partition function of the quicksort where last element is the pivot
//Input: arr[] = {3 8 6 12 10 7}  
//Expected Output: arr[] = {6 3 7 8 12 10}   (7 at its correct place)

//Solutuion
#include<iostream>
using namespace std;

int lomutoPartition(int* arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for(int j = 0; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[high]);
    return i + 1;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int index = lomutoPartition(arr, 0, n - 1);
    cout<<index<<endl;
    return 0;
}