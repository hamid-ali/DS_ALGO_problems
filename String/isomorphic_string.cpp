// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

bool areIsomorphic(string, string);

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        cout<<areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}// } Driver Code Ends


// This function returns true if str1 and str2 are ismorphic
// else returns false
#include<bits/stdc++.h>

bool areIsomorphic(string str1, string str2)
{
    unordered_map<char , char>  mp ;
    int m  = str1.length() , n = str2.length() ;
    
    if(m !=n ) return false;
    unordered_set<char> s;
    for(int i = 0 ; i < m ; i++)
    {
        
        if(mp.find(str1[i]) != mp.end() )
        {
            if(str2[i] == mp.find(str1[i])->second )
                continue;
            else return false;
        }
        
        else
        {
            if(s.find(str2[i]) != s.end())  return false;
            mp.insert({str1[i] , str2[i]}) ;
            s.insert(str2[i]);
        }
    }
    
    return true;
}

//Array based mapping
bool  areIsomorphic2(string str1, string str2)
{
    char map_arr[26]={0};
  char map_arr2[26]={0};
  int i=0,n1=str1.length(),n2=str2.length();
  if(n1!=n2) return false;
  size_t found = str1.find(str1[i]); 
  size_t found2 = str2.find(str2[i]); 

  
  while(i<n1){
      if(found==i && found2==i){map_arr[str1[i]-97]=str2[i];
          map_arr2[str2[i]-97]=str1[i];
      }
      else{
          if(map_arr[str1[i]-97]!=str2[i] || map_arr2[str2[i]-97]!=str1[i]) return false;
      }
      i++;
      found = str1.find(str1[i]);
      found2 = str2.find(str2[i]);
      
             }
  return true;
}