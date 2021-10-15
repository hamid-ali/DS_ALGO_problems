// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find floor of x
// n: size of vector
// x: element whose floor is to find
int findFloor(vector<long long> v, long long n, long long x)
{
    long long low = 0 , high = n-1 , mid = 0;
    if(n == 1){
        
        if(v[0] <=x) return 0 ;
        else 
            return -1;
                }
                
    while(low <= high)
    {
        mid = low + (high - low)/2 ;
        if(v[mid] == x) return mid ;
        else if( v[mid] < x )
        {   
            if(mid == n-1 || mid == 0) return mid; 

            if(x < v[mid+1])
            {
                return mid ;
            }
            
            low = mid + 1 ;
            
            
        }
        else high = mid ;
    }
    
    return -1;
    
}

// { Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    
	    cout << findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
} 