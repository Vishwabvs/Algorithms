#include<iostream>
using namespace std;
void merge(int arr[], int brr[], int m, int n, int c[])
{
    int i, j, k;
    i = j = k = 0;
    while(i<m && j<n)
    {
        if(arr[i] >= brr[j])
        {
            c[k] = brr[j];
            j++; 
        }
        else 
        {
            c[k] = arr[i];
            i++;
        }
        k++;
    }
    while(i<m)
    {
        c[k++] = arr[i++];
    }
    while(j<n)
    {
        c[k++] = arr[j++];
    }
}

int main()
{
    int m, n;
    cin>>m;
    int arr[m];
    for(int i=0;i<m;i++)
        cin>>arr[i];
    cin>>n;
    int brr[n];
    for(int i=0;i<n;i++)
        cin>>brr[i];
    int c[m+n];
    merge(arr, brr, m, n, c);
    for(int i=0;i<m+n;i++)
        cout<<c[i]<<" ";
    cout<<endl;
    if((m + n) % 2 != 0)
    {
        cout<<"Median: "<<c[(m+n)/2]<<endl;
    }
    else
    {
        cout<<"Median: "<<0.5 * (c[(m+n)/2-1]+c[(m+n)/2])<<endl;
    }
    
    return 0;
}