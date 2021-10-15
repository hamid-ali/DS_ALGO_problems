// { Driver Code Starts
#include <iostream>
using namespace std;

// Position this line where user code will be pasted.

int equilibriumPoint(long long a[], int n);

int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        //calling equilibriumPoint() function
        cout << equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to find equilibrium point
// a: input array
// n: size of array
int equilibriumPoint(long long arr[], int n)
{
    if(n==0 || n==1) return n;
    
    long long r_sum_arr[n]={};
    
    r_sum_arr[n-1] = arr[n-1];
    
    for(int i = n-2 ; i >= 0 ; i--)
    {
        r_sum_arr[i] = arr[i] + r_sum_arr[i+1] ;
    }
    
    long long l_sum=arr[0];
    
    if(l_sum == r_sum_arr[0])
            return 1;

    for(int i = 1 ; i < n ; i++)
    {
    
        l_sum = arr[i] + l_sum;

        if(l_sum == r_sum_arr[i])
            return i+1;
        
        
            
    }
    
    return -1;

    
}