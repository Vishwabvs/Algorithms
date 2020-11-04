//Given an array of size n, find the repeating element in the array

#include<iostream>
using namespace std;
int repeatingElement(int *arr, int n)
{
    int max1 = -99999;
    for(int i=0;i<n;i++)
    {
        max1 = max(max1, arr[i]); 
    }
    for(int i=0;i<n;i++)
    {
        
        if(arr[i]<0 && arr[i]<=max1)
            return i;
        arr[arr[i]] *= -1;
    }
    /*for(int i=0;i<=max1;i++)
    {
        if(arr[i] < 0)
    }*/
    return -1;

}
int repeatingElement2(int *arr, int n)
{
    //with No changes
    //Works well only if 1<=arr[i]<=n-2.. if we want to use with 0 also then increment arr[i] with 1 evertym 
    //and decrease the slow at the end.. the equivalent code is given in comments
    int slow = arr[0], fast = arr[0];     //int slow = arr[0]+1, fast = arr[0] + 1;
    do
    {
        slow = arr[slow];                 // slow = arr[slow] + 1;
        fast = arr[arr[fast]];            // fast = arr[arr[fast]+1]+1;
    } while (slow != fast);
    slow = arr[0];                        //slow = arr[0] + 1;
    while(slow != fast)     
    {
        slow = arr[slow];                 //slow = arr[slow] + 1;
        fast = arr[fast];                 //fast = arr[fast] + 1;
    }
    return slow;                          //return slow - 1;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<repeatingElement2(arr, n)<<endl;
    return 0;
}