// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends





/*  Function to check if str1 can be formed from
*   str2 after rotation by 2 places
*/
bool isRotated(string str1, string str2)
{
    int len1 = str1.length() , len2 = str2.length() ;
    if(len1 != len2) return false;
    bool flag = true ;
    int i = 2 ;
    for(i = 2 ; i < len1 + 2 ; i++)
    {
        if(str1[i % len1] != str2[i-2])
        {
            flag = false;
            break ;
        }
    }
    
    if(i == len1 +2) return flag = true ;
    
    for(i = 2 ; i < len1 + 2 ; i++)
    {
        if(str2[i % len1] != str1[i-2])
        {
            flag = false;
            break ;
        }
    }
    
    if(i == len1 +2) return flag = true ;
    
    return flag;   
}



// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		cout<<isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends