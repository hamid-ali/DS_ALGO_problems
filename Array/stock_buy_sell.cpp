#include <bits/stdc++.h>
using namespace std;
 
// solution structure
struct Interval
{
    int buy;
    int sell;
};



 // } Driver Code Ends


// solution structure
/* struct Interval
 {
     int buy;
     int sell;
 };*/

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n)
{
    int local_min = 0 , local_max = 0 ;
    bool sold=true;
    int i=0;
    
    if(price[i] < price[i + 1] )
        {
            local_min = i;
            sold = false;
        }
    
    for(i = 1 ; i < n-1 ; i++)
    {   
        if( !sold )
        {
            if( price[i] >= price[i-1] && price[i] > price[i+1] )
            
            {   local_max = i;
                cout << "(" << local_min<< " " << local_max <<")" <<" ";
                sold = true;
            }
        
        }
        
        if(sold)
        {
            if( price[i] <= price[i-1] && price[i] < price[i+1])
            {
                local_min = i;
                sold = false;
            }
        }
        
    }
    
    if( !sold )
    {
        
     if( price[i] > price[i-1] )
        local_max = i;
        
     local_max = i-1;
     cout << "(" << local_min<< " " << local_max <<")" <<" ";
     sold = true;
        
     
         
    }
    if( local_max == 0 ) cout<<"No Profit" ; 
    
    
}

// { Driver Code Starts.
 
// Driver program to test above functions
int main()
{   
    
    int price[10000],n,i,T;
    
    //testcases
    scanf("%d",&T);
    
    while(T--){
    
    //size of array
    scanf("%d",&n);
    
    //entering elements
    for(i=0;i<n;i++)
      scanf("%d",&price[i]);
    // fucntion call
    stockBuySell(price, n);
    cout<<endl;
    }
    return 0;
}