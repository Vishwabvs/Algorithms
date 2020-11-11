//Given n intervals, merge those intervals which are overlapping

//Solution
#include<iostream>
#include<algorithm>
using namespace std;
struct Interval
{
    int start;
    int end;
};
bool myCmp(Interval I1, Interval I2)
{
    return (I1.start < I2.start);    
}
void merge(Interval arr[], int n)
{
    sort(arr, arr + n, myCmp);
    int k = 1;
    for(int i = 1; i < n; i++)
    {
        if(arr[k - 1].end >= arr[i].start)
        {
            arr[k - 1].start = min(arr[k - 1].start, arr[i].start);
            arr[k - 1].end = max(arr[k - 1].end, arr[i].end);
        }
        else
        {
            arr[k] = arr[i];
            k++;
        }
    }

    for(int i = 0; i < k; i++)
        cout<<"("<<arr[i].start<<" "<<arr[i].end<<")"<<" "; 
}
int main()
{
    int n, a, b;
    cin>>n;
    Interval arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>a>>b;
        arr[i].start = a;
        arr[i].end = b;
    }
    merge(arr, n);
    return 0;
}