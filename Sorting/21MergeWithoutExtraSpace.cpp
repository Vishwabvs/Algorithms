//Given two sorted arrays arr1[] and arr2[] of sizes N and M in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements. 

//Solution
#include<iostream>
using namespace std;
//using gap method : O((m + n) log (m + n))
void merge(int* arr1, int* arr2, int m, int n)
{
    int size = m + n;
    int gap = size / 2;
    if(size % 2 != 0)
    {
        gap++;
    }
    cout<<gap<<endl;
    while(gap)
    {
        cout<<"hi "<<gap<<endl;
        for(int i = 0; i + gap < (m + n); i++)
        {
            int idx = i + gap;
            if(i < m && idx < m)
            {
                if(arr1[i] > arr1[idx])
                    swap(arr1[i], arr1[idx]);
            }
            else if(i < m && idx >= m)
            {
                //idx = idx - m;
                if(arr1[i] > arr2[idx - m])
                    swap(arr1[i], arr2[idx - m]);
            }
            else if(i >= m && idx >= m)
            {
                if(arr2[i - m] > arr2[idx - m])
                    swap(arr2[i - m], arr2[idx - m]);
            }
        }
        if(gap != 1 && gap % 2 != 0)
        {
            gap  = gap / 2 + 1;
        }
        else
        {
            gap = gap / 2;    
        }
    }
}
void merge2(int* arr1, int* arr2, int m, int n)
{
    int i = 0, j = 0, k = 0;
    int max1 = max(arr1[m - 1], arr2[n - 1]);
    max1++;
    while(i < m && j < n)
    {
        int e1 = arr1[i] % max1;
        int e2 = arr2[j] % max1;
        if(e1 <= e2)
        {
            if(k < m)
            {
                arr1[k] += e1*max1;
            }
            else
            {
                arr2[k - m] += e1*max1;
            }
            k++;
            i++;        
        }
        else
        {
            if(k < m)
            {
                arr1[k] += e2*max1;
            }
            else
            {
                arr2[k - m] += e2*max1;
            }
            k++;
            j++;
        }
    }
    while(i < m)
    {
        int e1 = arr1[i] % max1;
        if(k < m)
        {
            arr1[k] += e1*max1;
        }
        else
        {
            arr2[k - m] += e1*max1;
        }
        k++;
        i++;  
    }
    while(j < n)
    {
        int e2 = arr2[j] % max1;
        if(k < m)
        {
            arr1[k] += e2*max1;
        }
        else
        {
            arr2[k - m] += e2*max1;
        }
        k++;
        j++;
    }
    for(int i = 0; i < m; i++)
        arr1[i] = arr1[i] / max1;
    for(int i = 0; i < n; i++)
        arr2[i] = arr2[i] / max1;
}
int main()
{
    int m, n;
    cin>>m>>n;
    int arr1[m], arr2[n];
    for(int i = 0;i < m; i++)
        cin>>arr1[i];
    for(int i = 0; i < n; i++)
        cin>>arr2[i];
    merge2(arr1, arr2, m, n);
    for(int i = 0;i < m; i++)
        cout<<arr1[i]<<" ";
    cout<<endl;
    for(int i = 0; i < n; i++)
        cout<<arr2[i]<<" ";
    cout<<endl;
    
}