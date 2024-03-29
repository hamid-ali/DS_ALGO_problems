// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        unordered_map<int , int> mp;
        
        int n1 = str1.length() , n2 = str2.length() ;
        
        if(n1 != n2)
            return false ;
        
        for(int i = 0 ; i < n1 ; i++)
        {
            if(mp.count(str1[i]))
            {
                if(mp.find(str1[i])->second != str2[i] )
                    return false ;
                
                
                
            }
            
            else
            mp[str1[i]] = str2[i] ;
            
            
        }
        
        return true ;
        
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends
