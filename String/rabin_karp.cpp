// { Driver Code Starts
//Initial Template for C++

/* Following program is a C implementation of 
Rabin Karp. Algorithm given in the CLRS book */
#include<bits/stdc++.h>

using namespace std;

bool search(string, string, int);


 // } Driver Code Ends


//User function Template for C++

// d is the number of characters in the input alphabet 
#define d 256 

/* pat -> pattern 
	txt -> text 
	q -> A prime number 
*/
// bool search(string pat, string txt, int q) 
// { 
// 	int len_pat = pat.length() ;
// 	int len_txt = txt.length() ;
// 	int hash_val = 0 , h_txt = 0 ;
	
// 	for(int i = 0 ; i < len_pat ; i++)
// 	{
// 	    hash_val += pat[i] ;
// 	    h_txt += txt[i] ;
// 	}
	
// 	for(int i = 0 ; i <= len_txt - len_pat ; i++)
// 	{
// 	    int j = 0 ;
// 	    if(hash_val == h_txt)
// 	    {
// 	        for( j = 0 ; j < len_pat ; j++)
// 	        {
// 	            if(pat[j] != txt[j + i]) break;
	            
// 	        }
	        
// 	        if(j == len_pat) return true;
// 	    }
	    
// 	    h_txt += txt[i + len_pat] - txt[i]; 
	    
// 	}
	
// 	return false;
	
	
// } 

//Final soln optimised for handling collision

bool search(string pat, string txt, int q) 
{ 
    int m = pat.length() , n = txt.length() ;
    int h = 1 ;
    
    for(int i = 1; i <= m-1 ; i++)
    {
        h = (h * d) % q;
    }
    
    int p = 0 , t = 0 ;
    
    for(int i = 0 ; i < m ; i++)
    {
        p = (p*d + pat[i] ) % q ;
        t = (t*d + txt[i] ) % q ;
    }
    
    for(int i = 0 ; i <= n - m ; i++)
    {
        if(p == t)
        {
            bool flag = true;
            
            for(int j = 0 ; j < m ; j++)
            {
                if(pat[j] != txt[j+i]) { flag = false ; break ;}
            }
            
            if(flag) return true;
        }
        
        if(i <= n - m)
        {
            t = (d*(t - h*txt[i]) + txt[i+m] ) % q ;
            if(t < 0) t += q ;
        }
            
    }
	return false ;
	
} 


int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
	    string s, p;
	    cin >> s >> p;
	    int q = 101; // A prime number 
	    if(search(p, s, q)) cout << "Yes" << endl;
	    else cout << "No" << endl;
    }
	return 0; 
} 