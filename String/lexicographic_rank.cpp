// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends







const int CHAR=256; 
int fact(int n) 
{ 
    return (n <= 1) ? 1 : ((n % 1000000007) * (fact(n - 1) % 1000000007)) % 1000000007; 
} 
 
int findRank(string str) 
{ 
    int res = 1; 
    int n=str.length();
    int mul= fact(n);
    int count[CHAR]={0};
    for(int i=0;i<n;i++)
        count[str[i]]++;
    for(int i=1;i<CHAR;i++)
        {
            if(count[i] > 1) return 0 ;
            count[i]+=count[i-1];
            
        }
    for(int i=0;i<n-1;i++){
        mul=mul/(n-i);
        res=res+count[str[i]-1]*mul;
        for(int j=str[i];j<CHAR;j++)
            count[j]--;
    }
    return res;
} 


// { Driver Code Starts.


int main()
{
    string S;
    int t;
    cin>>t;
    while(t--)
    {
     
        cin>>S;
    cout<<findRank(S)<<endl;
    }
}
  // } Driver Code Ends