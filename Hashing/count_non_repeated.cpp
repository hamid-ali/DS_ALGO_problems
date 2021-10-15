#include <bits/stdc++.h>
using namespace std;

int countNonRepeated(int arr[], int n);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	    cout<<countNonRepeated(arr,n)<<endl;
	    
	}
	return 0;
}
// } Driver Code Ends


//Complete this function

int countNonRepeated(int arr[], int n)
{
    unordered_map<int , int> m;
    for(int i = 0 ; i < n ; i++)
    {
        if( m.count(arr[i]) )    (m.find(arr[i])->second) += 1 ;
        else
        {
            m.insert({arr[i] , 1});
        }
    }
    int count = 0 ;
    for(auto x = m.begin() ; x != m.end() ; x++)
    {
        if(x->second == 1) count++;
        
    }
    
    return count;
}
