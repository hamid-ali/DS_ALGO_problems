// { Driver Code Starts
// C++ program for Naive Pattern 
// Searching algorithm 
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


/*  function to search for a pattern with distinct characters
*   pat: pattern(to be searched in txt) given in the input
*   txt: string given in the input
*/
bool search(string pat, string txt) 
{ 
	int m = pat.length() , n = txt.length() ;
	
	int i = 0 ;
	while(i <= n - m)
	{
	    int j = 0 ;
	    
	        while(j < m)
	        {
	            if(pat[j] != txt[i+j])
	                break;
	           j++;
	        }
	    
	    if(j == m) return true;
	 
	    i += (0 < j - 1 ? j - 1 :1) ;
	    
	}
	
	return false;
	
	
} 

// { Driver Code Starts.

// Driver Code 
int main() 
{ 
	
	int t;
	cin >> t;
	
	while(t--){
	    string s, p;
	    cin >> s >> p;
	    if(search(p, s)) cout << "Yes"; else cout << "No"; cout << endl;
	}
	
	return 0; 
}  // } Driver Code Ends