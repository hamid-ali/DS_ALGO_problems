// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends





// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]
long long merge_count(long long arr[] , long long l , long long m , long long r )
{
    long long n1 = m - l+1 , n2 = r - m ;
    long long left[n1] , right[n2];
    
    for(long long i = 0 ; i < n1 ;i++ ) left[i] = arr[l+i];
    for(long long i = 0 ; i < n2 ;i++ ) right[i] = arr[m+i+1];
    long long i = 0  , j = 0 , k = l ;
    long long res = 0;
    while(i < n1 && j < n2)
    {
        if(left[i] <= right[j]) { arr[k] = left[i] ; i++ ;}
        else
        {
            arr[k] = right[j];
            j++ ; res = res + n1 - i ;
        }
        k++ ;
    }
    while(i < n1){ arr[k] = left[i] ; i++ ; k++; }
    while(j < n2){ arr[k] = right[j]; j++ ; k++; }
    return res;    
    
}

long long helper1(long long arr[] , long long low , long long high)
{
    long long res = 0;
    if(low < high)
    {
        int mid = low + (high-low)/2;
        res += helper1(arr, low , mid);
        res += helper1(arr , mid+1 ,high );
        res += merge_count(arr , low , mid , high );
    }
    
    return res;
}

// int res = 0 ;
long long int inversionCount(long long arr[], long long N)
{   long long ans = 0 ;
    long long low = 0 , high = N-1 ;
    ans = helper1(arr , low , high );
    
    return ans;

}



// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends


  /* Below is what is in simple form of it as on GFG :-

  */

int countInv(int arr[] , int l , int r)
{
    int res = 0 ;

    if(l < r)
    {
        int m = l + (h - l)/2 ;

        res += countInv(arr , l , m);

        res += countInv(arr , m+1 , r);

        res += countAndMerge(arr , l , m , r);
        
    }
    return res;
}

int countAndMerge( int arr [], int l , int m , int r)
{
    int n1 = m - l + 1 , n2 = r - m ;

    int left[n1] , right[n2] ;

    for(int i = 0 ; i < n1 ; i++) left[i] = arr[i] ;

    for(int i = 0 ; i < n2 ; i++) right[i] = arr[m+1+i] ;

    int i = 0 , j = 0 , k = l , res = 0 ;

    while(i < n1 && j < n2)
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i] ;
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            res += n1 - i ;
        }

        k++;

    }

    while(i < n1) {arr[k] = left[i] ; i++ ; k++; }

    while(j < n2) { arr[k] = right[j] ; j++; k++ ;}

    return res;

}