// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to sort the given array according to
// the difference with K
// A[]: input array
// N: size of array


void merge(int arr[], int low , int mid , int high , int key)
{
    int n1 = mid - low + 1 , n2 = high - mid ;
    int left[n1], right[n2];
    for(int i = 0  ; i < n1 ; i++)  left[i] = arr[low+i];
    for(int i = 0 ; i < n2 ; i++ )  right[i] = arr[mid + 1 + i];
    int i = 0 , j = 0 , k = low; 
    while(i < n1 && j < n2)
    {
        // if(abs(left[i] - key) == (abs(right[j] - key))) { arr[k++] = left[i++] ; }
        if(abs(left[i] - key) <= (abs(right[j] - key))) { arr[k++] = left[i++] ;  }
        
        else if(abs(left[i] - key) > (abs(right[j] - key))) { arr[k++] = right[j++] ; }
    }
    
    while(i < n1 ) { arr[k++] = left[i++]; }
    while(j < n2)  { arr[k++] = right[j++]; }
   
}


void merge_helper(int arr[] , int l , int h , int k)
{
    if(l < h)
    {
        int mid = l + (h - l)/2 ;
        
        merge_helper(arr , l , mid , k) ;
        merge_helper(arr , mid + 1 , h , k );
        merge(arr , l , mid , h , k);
    }

}


void sortABS(int A[],int N, int k)
{
   int l = 0 , h = N-1 ;
   merge_helper(A , l , h , k);
}


// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    
	    int N, diff;
	    cin>>N>>diff;
	    int A[N];
	    
	    for(int i = 0; i<N; i++)
	        cin>>A[i];
	   
	    sortABS(A, N, diff);
	    
	    for(int & val : A)
	        cout<<val<<" ";
	    cout<<endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends