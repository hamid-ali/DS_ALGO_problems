// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to print string after removing consecutive duplicates


string removeConsecutiveDuplicates(string s)
{
    stack< char > st ;
    long long n = s.length() ;
    // st.push(s[0]) ;
    for(long long i = n - 1 ; i >=0 ; i--)
    {
        if(!st.empty() && st.top() == s[i])
        {
            st.pop() ;
            
        }
        else
        {
            st.push(s[i]) ;
            
        }
        
    }
    
    string res ;
    while(!st.empty())
    {
        res.push_back(st.top()) ;
        st.pop() ;
    }
    
    return res ;
}

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        cout<<removeConsecutiveDuplicates(s)<<endl;
    }
    
	return 0;
}  // } Driver Code Ends