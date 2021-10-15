#include<bits/stdc++.h>
using namespace std;

void arrange(long long arr[], int n) 
{
    for(int i = 0 ; i < n ; i++)
    {
        arr[i] = arr[i] + (arr[arr[i] % n] % n) *n ;
    }
    
    for(int i = 0 ; i < n ; i++ )
    {
        arr[i] = arr[i] / n;
    }
    
}


// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin>>t;
    while(t--){
        
        int n;
        //size of array
        cin>>n;
        long long A[n];
        
        //adding elements to the array
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        
        //calling arrange() function
        arrange(A, n);
        
        //printing the elements 
        for(int i=0;i<n;i++){
            cout << A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}