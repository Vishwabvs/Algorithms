//Given an array of elements of three types, sort the array in such a way all the elements of given type occur together

//Solution
#include<iostream>
using namespace std;

void sort(int *arr, int n, int l, int r)
{
    int i = 0, j = n - 1;
    int low = 0, high = n - 1, mid = 0;
    while(mid < high)
    {
        if(arr[mid] < l)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] > r)
        {
            high--;
            swap(arr[high], arr[mid]);
        }
        else
        {
            mid++;
        }
        
    }
}

int main()
{
    int n, m;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int l, r;
    cin>>l>>r;
    sort(arr, n, l, r);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}