/*Given an array with positive  and negative elements, sort the array in such a way that all the positive elements are on one side 
and all the negative elements are on the other side*/

//Solution
#include<iostream>
using namespace std;
void sortPosNeg(int *arr, int n)
{
    int j = -1;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < 0)
        {
            j++;
            swap(arr[j], arr[i]);
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
    sortPosNeg(arr, n);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}