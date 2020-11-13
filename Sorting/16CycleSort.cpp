//Implementation of Cycle Sort

#include<iostream>
using namespace std;
int cycleSortDuplicates(int* arr, int n)
{
    int writes = 0;
    for(int cs = 0; cs < n - 1; cs++)
    {
        int item = arr[cs];
        int pos = cs;
        for(int i = cs + 1; i < n; i++)
            if(arr[i] < item)
                pos++;
        if(pos == cs)
            continue;
        while(item == arr[pos])
            pos++;
        if(pos != cs)
        {
            swap(item, arr[pos]);
            writes++;
        }
        while(pos != cs)
        {
            pos = cs;
            for(int i = cs + 1; i < n; i++)
                if(arr[i] < item)
                    pos++;
            
            while(item == arr[pos])
                pos++;

            if(item != arr[pos])
            {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }
    return writes;
}
void cycleSortDistinct(int* arr, int n)
{
    for(int cs = 0; cs < n - 1; cs++)
    {
        int pos  = cs;
        int item = arr[cs];
        for(int i = cs + 1; i < n; i++)
        {
            if(arr[i] < item)
                pos++;
        }
        swap(item, arr[pos]);
        while(cs != pos)
        {
            pos = cs;
            for(int i = cs + 1; i < n; i++)
            {
                if(arr[i] < item)
                    pos++;
            }
            swap(item, arr[pos]);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int writes = cycleSortDuplicates(arr, n);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"Total Writes: "<<writes<<endl;
    return 0;
}