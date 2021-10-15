// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


vector <int> max_of_subarrays(int *arr, int n, int k)
{
    deque<int> dq ;
    vector<int> res ;
    for(int i = 0 ; i < k ; i++)
    {
        if(dq.empty())
            dq.push_front(i);
            
        // else if(arr[i] < arr[dq.front()])
        //     dq.push_back(i) ;
            
        else if( arr[i] >= arr[dq.front()])
        {
            while(!dq.empty() && arr[i] >= arr[dq.front()])
            {
                dq.pop_front() ;
                
            }
            dq.push_front(i) ;
            
        }
        
    }
    
    res.push_back(arr[dq.front()]) ;
    
    int i = k ;

    for(i = k ; i < n - k  ; i++)
    {
        while(!dq.empty() && dq.front() <= (i - k ) ) dq.pop_front();
        
      if(!dq.empty() && arr[dq.front()] <= arr[i])
      {
      while(!dq.empty() && arr[dq.front()] <= arr[i])
      {
              dq.pop_front() ;
       }
          dq.push_front(i) ;
      
      }
      dq.push_back(i) ;
        res.push_back(arr[dq.front()]) ;
        
    }
       


    while(!dq.empty() && dq.front() <= (n - 1 - k ) ) dq.pop_front();
    if(!dq.empty() && arr[dq.front()] <= arr[n - k - 1])
      {
      
          dq.pop_front() ;

          dq.push_front(i) ;
      
      }
    else
      dq.push_back(n - 1) ;

    res.push_back(arr[dq.front()]) ;

    
    return res ;
}


// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    
	    vector <int> res = max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends