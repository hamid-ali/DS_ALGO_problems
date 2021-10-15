// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    
    int custum_search(int * arr , int  low , int high , int  key)
    {
        int mid = low + (high - low)/2 , res = 0;
        int l = low , h = high ;
        while(l <= h)
        {
            mid = l + (h - l)/2 ;

            if(arr[mid] >= key )
            {
                if(mid == low) return res;

                else if(arr[mid-1] < key) return (mid-low);

                h = mid - 1;
            }
            else
            {
                l = mid + 1;

            } 

        }
        
        if(mid == high) return high-low+1;
        return res;


    }

    int findNumberOfTriangles(int arr[], int n)
    {
        int i = 0 , j = 0 , k = 0 , count = 0;
        
        sort(arr , arr+n) ;
        
        for(i = 0 ; i < n - 2 ; i++ )
        {
            for(j = i+1 ; j < n -1 ; j++ )
            {
                 k = j +1 ;
                count += custum_search( arr , j+1 , n-1 , (arr[i]+arr[j])) ;

                // k = j +1 ;
                // while( k < n && arr[i] + arr[j] > arr[k] ){
                //     count++;
                //     k++;
                // }
                
            }
                
        }
        
        return count;
    }
};


// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}  // } Driver Code Ends