// { Driver Code Starts
// C++ program Find concatenated string with 
// uncommon characters of given strings 
#include <bits/stdc++.h> 
using namespace std; 

string concatenatedString(string, string);

/* Driver program to test above function */
int main() 
{ 
	int t;
	cin >> t;
	
	while(t--){
    	string s1, s2;
    	cin >> s1 >> s2;
    	string res = concatenatedString(s1, s2);
    	cout<<res<<endl;
	}
	return 0; 
}
// } Driver Code Ends


// Function which concatenate two strings
// after removing common characters
string concatenatedString(string s1, string s2) 
{ 
    string res = "" ;
    int m = s1.length() , n = s2.length() ;
    int i = 0;
    bool visited1[256] = {false} ;
    for(i = 0 ; i < n ; i++)
    {
        visited1[s1[i]] = true;
    }
    bool visited2[256] = {false} ;
    for(i = 0 ; i < m ; i++)
    {
       visited2[s2[i]] = true ; 
    }
    for(i = 0 ; i < m ; i++ )
    {
        if(visited2[s1[i]]) continue;
        res += s1[i] ;
    }
    
    for(i = 0 ; i < n ; i++)
    {
        if(visited1[s2[i]]) continue;
        res += s2[i] ;
    }
    
    if(res.length() > 0) return res;
    res = "-1" ;
    return res;
}
