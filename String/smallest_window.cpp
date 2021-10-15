// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// return the smallest window in S with all the characters of P
// if no such window exists, return "-1" 
string smallestWindow (string s, string t)
{
    // unordered_map<char , int> hash_table ;
    // int len_S = S.length() , len_P = P.length() ;
    // for(int i = 0 ; i < len_P ; i++)
    // {
    //     if(hash_table.count(P[i])) hash_table.find(P(i))->second++;
    //     else
    //         hash_table.insert({P[i] , 1}) ;
    // }
    
    // string res = "" , curr = "" ;
    // int start , end ;
    // for(int i = 0 ; i < len_S ; i++)
    // {
    //     if(hash_table.count)
        
        
    // }
    
    vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        while(end<s.size()){
            if(map[s[end++]]-- > 0) counter--; //in t
            while(counter==0){ //valid
                if(end-begin<d)  d=end-(head=begin);
                if(map[s[begin++]]++==0) counter++;  //make it invalid
            }  
        }
        return d==INT_MAX? "-1":s.substr(head, d);
    
    
}

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        
        cout<<smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  