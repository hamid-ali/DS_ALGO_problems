// { Driver Code Starts
// C++ implementation to find the character in first 
// string that is present at minimum index in second
// string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



int minIndexChar(string str, string patt)
{
    int res  = INT_MAX ;
    int n = patt.length() ;
    for(int i = 0 ; i < n ; i++)
    {
        size_t found = str.find(patt[i]); 
            if (found != string::npos) 
                res = min(res , int(found) );
    }
    
    return res ;
}

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    string patt;
	    cin>>str;
	    cin>>patt;
	    int ans = minIndexChar(str, patt);
	    if(ans == -1)cout<<"No character present";
	    else cout<<str[ans];
	    cout<<endl;
	}return 0;
}
  // } Driver Code Ends