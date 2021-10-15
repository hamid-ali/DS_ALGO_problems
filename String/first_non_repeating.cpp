// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

char nonrepeatingCharacter(string S);

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    
        char ans = nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends


// Complete this function
const int CHAR = 26;
char nonrepeatingCharacter(string S)
{
//   int visited[26] = {0} ;
//   int n = S.length() ;
//   for(int i = 0 ; i < n ; i++)
//   {
       
//       visited[S[i] - 'a']++ ;
       
//   }
   
//   for(int i = 0 ; i < n ; i++)
//   {
//       if( visited[S[i] - 'a'] ==1 ) return S[i];
       
//   }
   
//   return '$' ;
int fI[CHAR];
fill(fI, fI+CHAR , -1);
int n = S.length() ;
for(int i = 0 ; i < n ; i++)
{
    if(fI[S[i] - 'a'] == -1) fI[S[i] - 'a'] = i ;
    
    else fI[S[i] - 'a'] = -2 ;
}

int res = INT_MAX;

for(int i = 0 ; i < CHAR ; i++)
{
    if(fI[i] > -1)
        res = min(res , fI[i]);
    
}

return res == INT_MAX ? '$' : S[res];

}
