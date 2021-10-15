// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find the maximum difference of j-i
// arr[]: input array
// n: size of array
int maxIndexDiff(int arr[], int n) 
{
    int l_min=arr[0], maximum=0;
    int j=0,i=0;
    int r_max[n] = {0};
    r_max[n-1] = arr[n-1];
    
    for( i = n-2 ; i >=0 ; i--)
    {
        if(arr[i] > r_max[i+1])
        {   
            r_max[i] = arr[i] ;
            
        }
        
        else
            r_max[i] = r_max[i+1] ;
    }

    i = 0; j = 0 ;
    while(j < n && i < n )
    {
        

        if(l_min <= r_max[j])
            {
                maximum = max(maximum  , j-i);
                j++;
               
            }
         else
         {  i++;
            
            // if( arr[i] > r_max[j])
            //    i--;
            if( arr[i] < l_min)
                l_min = arr[i];
           
         }
    }
    
    return maximum;

    
}

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        
        //printing 0 if size is 1
        if(num ==1 ){
            cout<<0<<endl;
            continue;
        }
        
        //calling maxIndexDiff() function
        cout<<maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends