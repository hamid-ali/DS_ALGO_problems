// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> sortByFreq(int arr[],int n);

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    vector<int> v;
	    v = sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

// } Driver Code Ends


//Complete this function
//Return the sorted array
// Comparator function to sort pairs 
// according to second value 
bool cmp(pair<int , int>& a, 
         pair<int , int>& b) 
{ 
    if(a.second == b.second) return a.first < b.first ? true : false ;
    return a.second > b.second; 
} 
  
// Function to sort the map according 
// to value in a (key-value) pairs 
void sort(map<int, int>& M , vector<int> &res) 
{ 
  
    // Declare vector of pairs 
    vector<pair<int , int> > A; 
  
    // Copy key-value pair from Map 
    // to vector of pairs 
    for (auto& it : M) { 
        A.push_back(it); 
    } 
  
    // Sort using comparator function 
    sort(A.begin(), A.end(), cmp); 
  
    // Print the sorted value 
    for (auto& it : A) { 
  
        // cout << it.first << ' '
        //      << it.second << endl; 
        while(it.second--)
            res.push_back(it.first);
        
    } 
} 
vector<int> sortByFreq(int arr[],int n)
{
    map<int , int> M;
    for(int i = 0 ; i < n ; i++)
    {
        M[arr[i]]++;
        
    }
    
    vector <int> res;
    
    sort(M , res);
    
    return res;
    
}