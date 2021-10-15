// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


// Function to merge two input arrays
// arr1[], arr2[]: input arrays
// n, m: size of arr1[] and arr2[] respectively
void merge(int arr1[], int arr2[], int n, int m) 
{ 
    int i = 0 , j = 0 , k = 0 ;
    while( i < n && j < m)
    {
        if(arr1[i] <= arr2[j]) i++;
        
        else
        {  
            swap(arr1[i++] , arr2[j]);
            int temp = arr2[j] ;
            k = j+1 ;
            while(k < m && temp > arr2[k])
            {
                swap(arr2[k++] , arr2[k-1]);
            }
            
            // if(arr2[j] > arr2[j+1])
            // {
            //     int low = j+1 , hi = m - 1 ;
                
            //     while(low <= hi)
            //     {
            //     int mid = low + (hi - low)/2 ;
                
            //     if(arr2[mid] >= arr2[j] )
            //     {
                    
            //         if(arr2[mid - 1] < arr2[j] )
            //             { swap(arr2[j] , arr2[mid]) ; break; }
                    
            //         hi = mid - 1;
            //     }
                
            //     else low = mid + 1 ;
            //     }
            // }
            
            }
            
            
        }

} 


// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    int arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    
	    merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            printf("%d ", arr1[i]); 
        
       
	    for (int i = 0; i < m; i++) 
		    printf("%d ", arr2[i]); 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends