#include<iostream>
#include<climits>
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
        c[k++] = brr[j++];
    }
}
double findMedian(int* arr, int* brr, int m, int n)
{
    int c[m+n];
    merge(arr, brr, m, n, c);
    for(int i=0;i<m+n;i++)
        cout<<c[i]<<" ";
    cout<<endl;
    if((m + n) % 2 != 0)
    {
        return c[(m+n)/2];
    }
    else
    {
        return 0.5 * (c[(m+n)/2-1]+c[(m+n)/2]);
    }
}
double findMedian_efficient(int* arr, int* brr, int m, int n)
{
    //O(log(min(m, n))) approach
    int low = 0, high = m, i1, i2;
    while(low<=high)
    {
        i1 = (low + high)/2;
        i2 = ((m+n+1)/2)-i1;
        int min1 = (i1 == m) ? INT_MAX : arr[i1];
        int max1 = (i1 == 0) ? INT_MIN : arr[i1 - 1];
        int min2 = (i2 == n) ? INT_MAX : brr[i2];
        int max2 = (i2 == 0) ? INT_MIN : brr[i2 - 1];
        if(max1 <= min2 && max2 <= min1)
        {
            if((m+n)%2 == 0)
            {
                return (max(max1, max2)+ min(min1, min2))/2.0;
            }
            else 
            {
                return max(max1, max2);
            }
        }
        if(max1 > min2)
        {
            high = i1 - 1; 
        }
        else
        {
            low = i1 + 1;
        }
    }
    return -1;
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
    cout<<findMedian(arr, brr, m, n)<<endl;
    if(m<=n)
        cout<<findMedian_efficient(arr, brr, m, n)<<endl;
    else
        cout<<findMedian_efficient(brr, arr, n, m)<<endl;
    return 0;
}