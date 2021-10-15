#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// void swap(int &a , int &b)
// {
//     int temp = a;
//     a = b ;
//     b = temp;
// }

//
int partition(int arr[], int low, int high)
{
    int i = low - 1, j = low;
    int key = arr[high];
    while (j < high)
    {
        if (arr[j] >= key)
            j++;
        else
        {
            int temp = arr[i + 1];
            arr[i + 1] = arr[j];
            arr[j] = temp;
            i++;
            j++;
        }
    }
    if (i < high)
    {
        int temp = arr[i + 1];
        arr[i + 1] = key;
        arr[high] = temp;
        return i + 1;
    }
    return i;
}

int kthSmallest(int arr[], int n, int k)
{
    int l = 0, r = n - 1;

    while (l <= r)
    {
        int p = partition(arr, l, r);

        if (p == k - 1)
            return arr[p];

        else if (p > k - 1)
            r = p - 1;
        else
            l = p + 1;
    }

    return -1;
}

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int arr[n];

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        cout << kthSmallest(arr, n, k) << endl;
    }
    return 0;
} // } Driver Code Ends