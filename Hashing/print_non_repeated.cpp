// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> printNonRepeated(int arr[],int n);


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
	    
	    vector<int> v;
	    v = printNonRepeated(arr,n);
	    
	    for(int i=0;i<v.size();i++)  
	        cout<<v[i]<<" ";
	    
	    cout<<endl;
	    
	}
	return 0;
}

// } Driver Code Ends


// Function to print the non repeated elements in the array
// arr[]: input array
// n: size of array
vector<int> printNonRepeated(int arr[],int n)
{
    vector<int> res;
     unordered_map<int , int> m;
    for(int i = 0 ; i < n ; i++)
    {
        if( m.count(arr[i]) )    (m.find(arr[i])->second) += 1 ;
        else
        {
            m.insert({arr[i] , 1});
        }
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        if(m.find(arr[i]) != m.end())
        {
            if(m.find(arr[i])->second ==1)
            {
                res.push_back(arr[i]);
                m.erase(arr[i]);
            }
            
        }
        
    }
    
    return res;
    
    
}