//https://www.geeksforgeeks.org/construction-of-longest-increasing-subsequence-using-dynamic-programming/
//Print LIS

//Solution (DP):
#include<iostream>
#include<climits>
#include<vector>
#include<cstring>
using namespace std;
void lis(int arr[],int n,int& max_len)
{
    vector<vector<int>> result(n);
    //int *lookup = new int[n];
    result[0].push_back(arr[0]);

    //lookup[0] = 1;

    for(int i = 1;i < n;i++)
    {
        //lookup[i] = 1;
        for(int j = 0;j < i;j++)
        {
            //if(arr[j]<arr[i] && lookup[j]+1 > lookup[i])
            if(arr[j]<arr[i] && (result[i].size()<(result[j].size()+1)))
            {
                //lookup[i]++;
                result[i] = result[j];
            }
        }
        result[i].push_back(arr[i]);
    }
    /*for(int i=0;i<n;i++)
    {
        if(lookup[i]>max_len)
            max_len = lookup[i];
    }*/

    vector<int> max = result[0];
    for(vector<int> x:result)
    {
        if(x.size()>max.size())
            max = x;
    }

    for(int x:max)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[] = { 3, 2, 6, 4, 5, 1 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_len = INT_MIN;
    lis(arr,n,max_len);
    //cout<<"Length of longest subsequence is: "<<max_len<<endl;
    return 0;
}
