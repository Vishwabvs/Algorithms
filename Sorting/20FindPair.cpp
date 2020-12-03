//Given two arrays X and Y of positive integers, find the number of pairs such that xy > yx (raised to power of) where x is an element from X and y is an element from Y.

//Solution
#include<bits/stdc++.h>
using namespace std;

// Function to count number of pairs such that x^y is greater than y^x
// X[], Y[]: input arrau
// m, n: size of arrays X[] and Y[] respectively
int findCeil(int* arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
long long countPairs(int x[], int y[], int m, int n)
{
    sort(y, y + n);
    int zero = 0, one = 0, two = 0, three = 0, four = 0;
    for(int i = 0; i < n; i++)
    {
        if(y[i] == 0)
            zero++;
        else if(y[i] == 1)
            one++;
        else if(y[i] == 2)
            two++;
        else if(y[i] == 3)
            three++;
        else if(y[i] == 4)
            four++;
    }
    long long ans = 0;
    for(int i = 0; i < m; i++)
    {
        if(x[i] == 0)
            continue;
        else if(x[i] == 1)
            ans += zero;
        else
        {
            int index = findCeil(y, n , x[i]);
            if(index != -1)
                ans += n - index;
            ans += one + zero;
            if(x[i] == 2)
                ans -= (three + four);
            if(x[i] == 3)
                ans += two;
        }
    }
    return ans;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		cout<<countPairs(a, b, M, N)<<endl;
	}
}