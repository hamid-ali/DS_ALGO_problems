// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Functio to find first smallest positive
// missing number in the array
int missingNumber(int arr[], int n)
{
    for(int i=0 ; i < n ; i++)
        {
            if(arr[i] < 0 || arr[i] >= n+1)
                arr[i]=0;
        }
    
    for(int i = 0 ; i < n ; i++)
    {   if(((arr[i]) % (n+1)) !=0)
        arr[(arr[i]-1) % (n+1)] += n+1 ;
    }
    
    for(int i = 0 ; i < n ; i++ )
    {
        if((arr[i] / (n+1) ) == 0)
            return i+1;
    }
    
    return n+1;
    
    
    
} 

// { Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        //calling missingNumber()
        cout<<missingNumber(arr, n)<<endl;
    }
    return 0; 
} 