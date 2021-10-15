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
    
    while(low < high)
    {
        mid = high - (high - low)/2 ;
        if(v[mid] == x) return mid ;
        else if( v[mid] > x )
            high = mid ;
        else low = mid ;
    }
    if(v[low] > x)
    return -1;
    return low;
    
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